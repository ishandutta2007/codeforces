#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        map<pii, long long> mp;
        int n;
        cin >> n;
        long long l = 2e9, r = 0, mnl = 2e9, mnr = 2e9;
        for(int i = 0; i < n; i++) {
            long long u, v, w;
            cin >> u >> v >> w;
            if(mp.count({u,v})) mp[{u,v}] = min(mp[{u,v}], w);
            else mp[{u,v}] = w;
            if(l == u) mnl = min(mnl, w);
            if(u < l) {
                l = u;
                mnl = w;
            }
            if(r == v) mnr = min(mnr, w);
            if(v > r) {
                r = v;
                mnr = w;
            }
            if(!mp.count({l, r})) cout << mnl + mnr << endl;
            else cout << min(mnl + mnr, mp[{l, r}]) << endl;
        }
    }
    return 0;
}