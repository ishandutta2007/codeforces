#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans[1000002], m, w, o=0;
vector<long long> v;
deque<pair<ll, ll> >q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> w;
    for (ll i=1; i<=m; i++) {
        ll n;
        cin >> n;
        if (w>=2*n) {
            v.clear();
            for (int i=1; i<=n; i++) {
                int x;
                cin >> x;
                v.push_back(x);
            }
            ll el=0, maxi=0;
            for (ll i=1; i<=n; i++) {
                ll x=v[i-1];
                maxi=max(x, el);
                ans[i]+=maxi-el;
                el=maxi;
            }
            el=0;
            for (ll i=n; i>=1; i--) {
                ll x=v[i-1];
                maxi=max(x, el);
                ans[w+i-n+1]-=maxi-el;
                el=maxi;
            }
        } else {
            q.clear();
            ll el=0, maxi=-INT_MAX;
            for (ll i=1; i<=w; i++) {
                if (i<=n) {
                    ll x;
                    cin >> x;
                    while(q.size()>0 && x>q.back().second) {
                        q.pop_back();
                    }
                    q.push_back({i, x});
                }
                while(q.size()>0 && n+i-q.front().first>w) {
                    q.pop_front();
                }
                maxi=q.front().second;
                if (i>n || i+n<=w) {
                    maxi=max(o, maxi);
                }
                ans[i]+=maxi-el;
                el=maxi;
            }
        }
    }
    for (ll i=1; i<=w; i++) {
        cout << ans[i]+ans[i-1] << " ";
        ans[i]+=ans[i-1];
    }
    return 0;
}