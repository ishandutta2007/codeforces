#include <bits/stdc++.h>

using namespace std;
const long long e=1, t=63, db=16, c=1002;
int d, n, q, k;
vector<long long> u(db, 0), sz[c], res[1<<15], p, s;
map<vector<long long>, int> par;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> d >> n >> q, k=min(n, 10);
    for (int i=0; i<n; i++) {
        p=u;
        int x; cin >> x;
        for (int i=1; i<=x; i++) {
            long long y; cin >> y;
            p[y/t]+=(e<<(y%t));
        }
        sz[i]=p;
    }
    for (int i=0; i<(1<<k); i++) {
        p=u;
        for (int j=0; j<k; j++) {
            if (i&(1<<j)) {
                for (int l=0; l<db; l++) {
                    p[l]^=sz[j][l];
                }
            }
        }
        res[i]=p;
    }
    for (int i=0; i<(1<<(n-k)); i++) {
        p=u;
        for (int j=k; j<n; j++) {
            if (i&(1<<(j-k))) {
                for (int l=0; l<db; l++) {
                    p[l]^=sz[j][l];
                }
            }
        }
        int x=__builtin_popcount(i);
        if (par.find(p)==par.end()) {
            par[p]=x;
        } else {
            par[p]=min(par[p], x);
        }
    }
    for (int i=0; i<q; i++) {
        int mini=n+1;
        p=u;
        int x; cin >> x;
        for (int i=1; i<=x; i++) {
            long long y; cin >> y;
            p[y/t]+=(e<<(y%t));
        }
        for (int j=0; j<(1<<k); j++) {
            s=u;
            for (int l=0; l<db; l++) {
                s[l]=p[l]^res[j][l];
            }
            if (par.find(s)!=par.end()) {
                mini=min(mini, par[s]+__builtin_popcount(j));
            }
        }
        if (mini==n+1) mini=-1;
        cout << mini << "\n";
    }
    return 0;
}