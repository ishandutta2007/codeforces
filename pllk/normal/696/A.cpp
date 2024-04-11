#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int q;
map<pair<ll,ll>,ll> z;

int main() {
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            ll v, u, w;
            cin >> v >> u >> w;
            while (true) {
                if (v == u) break;
                if (v > u) {
                    z[make_pair(v,v/2)] += w;
                    z[make_pair(v/2,v)] += w;
                    v /= 2;
                } else {
                    z[make_pair(u,u/2)] += w;
                    z[make_pair(u/2,u)] += w;
                    u /= 2;
                }
            }
        }
        if (t == 2) {
            ll v, u;
            cin >> v >> u;
            ll s = 0;
            while (true) {
                if (v == u) break;
                if (v > u) {
                    s += z[make_pair(v,v/2)];
                    v /= 2;
                } else {
                    s += z[make_pair(u,u/2)];
                    u /= 2;
                }
            }
            cout << s << "\n";
        }
    }
}