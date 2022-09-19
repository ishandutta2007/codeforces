#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, ert[c];
vector<int> sz[c];
vector<pair<int, int> > akt[c];
bool v[c], h[c];
void dfs(int a) {
    //cout << "dfs " << a << endl;
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            akt[a].push_back({ert[x], x});
        }
    }
    sort(akt[a].rbegin(), akt[a].rend());
    while (akt[a].size()>0 && abs(ert[a]-akt[a].back().first)<=1) {
        int id=akt[a].back().second;
        if (ert[a]!=1 && ert[a]==ert[id]) {
            break;
        }
        //cout << "ujel " << a << " " << id << "\n";
        ert[a]=max(ert[a], ert[id])+1;
        akt[a].pop_back();
        for (auto j:akt[id]) {
            akt[a].push_back(j);
        }
        sort(akt[a].rbegin(), akt[a].rend());
    }
    if (!ert[a]) {
        ert[a]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!ert[i]) {
            ert[i]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>=30) {
            cout << "NO\n";
            return 0;
        }
    }
    dfs(1);
    if (akt[1].size()>0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}
/*
13
1 2
2 3
3 4
4 5
1 6
6 7
7 8
8 9
6 10
10 11
11 12
10 13
*/