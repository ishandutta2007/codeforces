#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 2e9 + 100;

bool vis[maxn];

map<string, vector<int> > q[2];

string s[maxn][2];

int n;

int mas[maxn], cnt;

set<string> w;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        s[i][0].push_back(a[0]);
        s[i][0].push_back(a[1]);
        s[i][0].push_back(a[2]);
        q[0][s[i][0]].push_back(i);
        s[i][1].push_back(a[0]);
        s[i][1].push_back(a[1]);
        s[i][1].push_back(b[0]);
        q[1][s[i][1]].push_back(i);
    }
    for (auto i : q[0])
    if (i.second.size() > 1){
        for (int j = 0; j < i.second.size(); j++)
            vis[i.second[j]] = 1, mas[cnt] = i.second[j], cnt++;
    }
    for (int i = 0; i < cnt; i++){
        int v = mas[i];
        if (q[0].find(s[v][1]) != q[0].end()){
            for (int j = 0; j < q[0][s[v][1]].size(); j++){
                int to = q[0][s[v][1]][j];
                if (!vis[to])
                    vis[to] = 1, mas[cnt] = to, cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    if (vis[i]){
        if (w.find(s[i][1]) != w.end()){
            cout << "NO";
            return 0;
        }
        w.insert(s[i][1]);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    if (vis[i])
        cout << s[i][1] << '\n';
    else
        cout << s[i][0] << '\n';
}