#include <bits/stdc++.h>
 
using namespace std;
int n;
vector<int> sz[200001];
long long maxi;
int t[200001];
long long e[200001];
bool v[200001];
long long ert;
void solve(int a)
{
    v[a]=true;
    maxi=max(maxi, ert);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            ert+=n;
            ert-=2*t[x];
            solve(x);
            ert-=n;
            ert+=2*t[x];
        }
    }
}
void dfs(int a) {
    v[a]=true;
    t[a]++;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            t[a]+=t[x];
            e[a]+=e[x];
            e[a]+=t[x];
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    dfs(1);
    e[1]+=n;
    for (int i=1; i<=n; i++) {
        v[i]=false;
    }
    ert=e[1];
    solve(1);
    cout << maxi << endl;
    return 0;
}