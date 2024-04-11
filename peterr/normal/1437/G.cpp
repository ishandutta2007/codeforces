#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
vector<vector<int>> nxt;
vector<int> suf;
vector<int> near;
vector<int> par;
vector<int> chr;
vector<int> val;
vector<bool> leaf;
vector<vector<int>> go;
vector<priority_queue<pair<int, int>>> pq;
int pos[MAXN];
int sus[MAXN];

void addNode(int p, int key)
{
    nxt.push_back(vector<int>(26, -1));
    suf.push_back(-1);
    near.push_back(-1);
    par.push_back(p);
    chr.push_back(key);
    val.push_back(0);
    leaf.push_back(false);
    go.push_back(vector<int>(26, -1));
    pq.push_back(priority_queue<pair<int, int>>());
}

int getGo(int v, int key);

int getSuf(int v)
{
    if (suf[v] == -1)
    {
        if (par[v] == 0)
            suf[v] = 0;
        else
            suf[v] = getGo(getSuf(par[v]), chr[v]);
    }
    return suf[v];
}

int getNearest(int v)
{
    if (near[v] == -1)
    {
        int p = getSuf(v);
        if (leaf[p])
            near[v] = p;
        else
            near[v] = getNearest(p);
    }
    return near[v];
}

int getGo(int v, int key)
{
    if (go[v][key] == -1)
    {
        if (nxt[v][key] != -1)
            go[v][key] = nxt[v][key];
        else if (!v)
            go[v][key] = 0;
        else
            go[v][key] = getGo(getSuf(v), key);
    }
    return go[v][key];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    addNode(0, -1);
    val.back() = -1;
    leaf.back() = true;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int cur = 0;
        for (char ch : s)
        {
            int key = ch - 'a';
            if (nxt[cur][key] == -1)
            {
                nxt[cur][key] = (int) nxt.size();
                addNode(cur, key);
            }
            cur = nxt[cur][key];
        }
        pos[i] = cur;
        leaf[cur] = true;
        pq[cur].push(make_pair(0, i));
    }
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            string q;
            cin >> q;
            int cur = 0;
            int ans = -1;
            for (char ch : q)
            {
                int key = ch - 'a';
                cur = getGo(cur, key);
                int j = cur;
                if (leaf[j])
                    ans = max(ans, val[j]);
                while (j)
                {
                    j = getNearest(j);
                    ans = max(ans, val[j]);
                }
            }
            cout << ans << "\n";
        }
        else
        {
            int ind, x;
            cin >> ind >> x;
            ind--;
            sus[ind] = x;
            pq[pos[ind]].push(make_pair(x, ind));
            while(pq[pos[ind]].top().first != sus[pq[pos[ind]].top().second])
                pq[pos[ind]].pop();
            val[pos[ind]] = pq[pos[ind]].top().first;
        }
    }
    return 0;
}