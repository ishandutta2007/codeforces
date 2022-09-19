#include <bits/stdc++.h>

using namespace std;
int n, cnt, maxi;
vector<int> sz[100002];
int bv[100002], nb[100002];
bool v[100002];
void dfs(int a) {
    v[a]=true;
    int p=0, q=0, r=0, s=0, si=sz[a].size();
    for (int i=0; i<si; i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            q=max(q, bv[x]), s=max(s, nb[x]);
            if (q>p) swap(p, q);
            if (s>r) swap(r, s);
        }
    }
    maxi=max({maxi, 1+r+s, si-2+p+q});
    nb[a]=si-2+p, bv[a]=1+r;
    bv[a]=max(bv[a], nb[a]);
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
    cout << maxi << "\n";
    return 0;
}
// Szp feladat, mdostott mlygi bejrs, megrte lerni. 2473