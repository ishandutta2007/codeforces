#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long
mt19937 rnd(51);

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    set<ll> st;
    map<ll, set<ll>> need;
    map<ll, vector<ll>> add;
    map<ll,ll> ans;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            ll x;
            cin >> x;
            st.insert(x);
        } else if (c == '-') {
            ll x;
            cin >> x;
            st.erase(x);
            for (auto to : add[x]) {
                need[to].insert(x);
            }
            add[x].clear();
        } else {
            ll k;
            cin >> k;
            if (!ans.count(k)) {
                ans[k] = k;
            }
            while (need[k].size() > 0) {
                ll val = *need[k].begin();
                if (st.count(val)) {
                    add[val].pb(k);
                    need[k].erase(val);
                } else {
                    break;
                }
            }
            if (need[k].size() == 0) {
                while (1) {
                    ll val = ans[k];
                    if (st.count(val)) {
                        add[val].pb(k);
                        ans[k] += k;
                    } else {
                        break;
                    }
                }
                cout << ans[k] << endl;
            } else {
                cout << *need[k].begin() << endl;
            }
        }
    }
    return 0;
}