#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, db, cent, h, sum, kcnt, ncnt, f[c], rf[c], ert[c];
vector<int> sz[c];
vector<pair<int, int> > k;
bool v[c], v2[c], kis[c], v3[c];
void dfs(int a) {
    v[a]=true, rf[a]=1;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            rf[a]+=rf[x];
        }
    }
    if (rf[a]>=h && !cent) {
        cent=a;
    }
}
void dfs2(int a) {
    v2[a]=true, rf[a]=1;
    for (int x:sz[a]) {
        if (!v2[x]) {
            f[x]=a;
            dfs2(x);
            rf[a]+=rf[x];
            if (a==cent) {
                k.push_back({rf[x], x});
            }
        }
    }
}
void dfs3(int a) {
    v3[a]=true;
    if (a!=cent) {
        if (kis[a]) {
            kcnt++;
            ert[a]=kcnt;
        } else {
            ncnt+=sum+1;
            ert[a]=ncnt;
        }
        cout << a << " " << f[a] << " " << ert[a]-ert[f[a]] << "\n";
    }
    for (int x:sz[a]) {
        if (!v3[x]) {
            if (kis[a]) {
                kis[x]=1;
            }
            dfs3(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, h=(n+1)/2;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1), dfs2(cent);
    sort(k.rbegin(), k.rend());
    for (pair<int, int> i:k) {
        if (sum+i.first<=h) {
            sum+=i.first, kis[i.second]=1;
        }
    }
    dfs3(cent);
    return 0;
}