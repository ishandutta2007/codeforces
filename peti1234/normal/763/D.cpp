#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, si[c], cent, cnt, maxi, cs;
vector<int> sz[c];
bool v[c], v2[c], v3[c];
map<unsigned long long, int> m;
unsigned long long sp=1123581321, dp[c], sum[c], sqsum[c];
void add(unsigned long long x, int id) {
    m[x]+=id;
    if (id==1 && m[x]==1) cnt++;
    if (id==-1 && m[x]==0) cnt--;
}
void dfs(int a) {
    v[a]=true;
    si[a]=1;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            si[a]+=si[x];
        }
    }
    if (2*si[a]>n && !cent) {
        cent=a;
    }
}
void dfs2(int a) {
    v2[a]=true;
    for (auto x:sz[a]) {
        if (!v2[x]) {
           dfs2(x);
           sum[a]+=dp[x], sqsum[a]+=dp[x]*dp[x];
        }
    }
    dp[a]=sum[a]+sqsum[a]+sp;
    add(dp[a], 1);
}
void dfs3(int a) {
    v3[a]=true;
    add(dp[a], -1);
    cnt++;
    if (cnt>maxi) {
        maxi=cnt;
        cs=a;
    }
    for (auto x:sz[a]) {
        if (!v3[x]) {
            dfs3(x);
        }
    }
    add(dp[a], 1);
    cnt--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    dfs2(cent);
    dfs3(cent);
    cout << cs << "\n";
    return 0;
}