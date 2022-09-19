#include <bits/stdc++.h>

using namespace std;
const int c=(1<<20);
int n, k;
bool v[c];
void pb(vector<vector<int> > &sz, int a, int b, int c) {
    sz[0].push_back(a), sz[1].push_back(b), sz[2].push_back(c);
}
void solve(vector<vector<int> > &sz, int a) {
    sz.resize(3);
    if (a>=k) {
        if (v[a-k]) {
            pb(sz, c, a-k, a-k);
        } else {
            pb(sz, c, -1, -1);
        }
        return;
    }
    vector<vector<int> > l, r;
    solve(l, 2*a), solve(r, 2*a+1);
    int si=l[0].size();
    for (int i=0; i<si; i++) {
        int aa=min(l[0][i], r[0][i]);
        if (l[2][i]!=-1 && r[1][i]!=-1) {
            aa=min(aa, r[1][i]-l[2][i]);
        }
        int bb=(l[1][i]!=-1 ? l[1][i] : r[1][i]), cc=(r[2][i]!=-1 ? r[2][i] : l[2][i]);
        pb(sz, aa, bb, cc);
    }

    for (int i=0; i<si; i++) {
        int aa=min(l[0][i], r[0][i]);
        if (r[2][i]!=-1 && l[1][i]!=-1) {
            aa=min(aa, l[1][i]-r[2][i]+2*si);
        }
        int bb=(r[1][i]!=-1 ? r[1][i]-si : l[1][i]!=-1 ? l[1][i]+si : -1), cc=(l[2][i]!=-1 ? l[2][i]+si : r[2][i]!=-1 ? r[2][i]-si : -1);
        pb(sz, aa, bb, cc);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k=(1<<k);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v[x]=1;
    }
    vector<vector<int>> ans;
    solve(ans, 1);
    for (int i=0; i<k; i++) {
        cout << ans[0][i] << " ";
    }
    cout << "\n";
    return 0;
}