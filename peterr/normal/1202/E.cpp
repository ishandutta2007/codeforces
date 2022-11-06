#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
string s[MAXN];
vector<vector<int>> go;
vector<int> pch;
vector<int> par;
vector<int> suf;
vector<vector<int>> nxt;
vector<int> leaf;
vector<int> val;

int getGo(int node, int ch);

int getSuf(int node)
{
    if (suf[node] == -1)
    {
        if (node == 0 || par[node] == 0)
            suf[node] = 0;
        else
            suf[node] = getGo(getSuf(par[node]), pch[node]);
    }
    return suf[node];
}

int getGo(int node, int ch)
{
    if (go[node][ch] == -1)
    {
        if (nxt[node][ch] != -1)
            go[node][ch] = nxt[node][ch];
        else if (node == 0)
            go[node][ch] = 0;
        else
            go[node][ch] = getGo(getSuf(node), ch);
    }
    return go[node][ch];
}

int getVal(int node)
{
    if (val[node] == -1)
    {
        if (node == 0)
            val[node] = 0;
        else
        {
            val[node] = leaf[node];
            val[node] += getVal(getSuf(node));
        }
    }
    return val[node];
}

void addNode(int parentCh, int parent)
{
    go.push_back(vector<int>(26, -1));
    pch.push_back(parentCh);
    par.push_back(parent);
    suf.push_back(-1);
    nxt.push_back(vector<int>(26, -1));
    leaf.push_back(0);
    val.push_back(-1);
}

void solve(string &t, int n, vector<int> &cnt)
{
    go.clear();
    pch.clear();
    par.clear();
    suf.clear();
    nxt.clear();
    leaf.clear();
    val.clear();
    addNode(-1, 0);
    for (int i = 0; i < n; i++)
    {
        int curNode = 0;
        for (char ch : s[i])
        {
            int key = ch - 'a';
            if (nxt[curNode][key] == -1)
            {
                nxt[curNode][key] = (int) go.size();
                addNode(key, curNode);
            }
            curNode = nxt[curNode][key];
        }
        leaf[curNode]++;
    }
    int node = 0;
    getSuf(2);
    for (int i = 0; i < (int) t.length(); i++)
    {
        int key = t[i] - 'a';
        node = getGo(node, key);
        cnt[i] = getVal(node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t;
    int n;
    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<int> pref((int) t.length());
    vector<int> suf((int) t.length());
    solve(t, n, pref);
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++)
    {
        reverse(s[i].begin(), s[i].end());
    }
    solve(t, n, suf);
    reverse(suf.begin(), suf.end());
    long long ans = 0;
    for (int i = 0; i < (int) t.length() - 1; i++)
    {
        ans += (long long) pref[i] * suf[i + 1];
    }
    cout << ans << "\n";
    return 0;
}