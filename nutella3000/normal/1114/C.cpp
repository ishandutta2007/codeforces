#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll b,n;
    cin >> n >> b;
    vector<pair<ll,ll>> del;
    for(int i = 2;i <= sqrt(b);i++) {
        while(b % i == 0) {
            if (del.size() == 0 || del[del.size() - 1].first != i) {
                del.push_back(pair<ll,ll>(i,1));
            }else del[del.size() - 1].second++;
            b /= i;
        }
    }
    if (b != 1) del.push_back(pair<ll,ll>(b,1));
    vector<ll> cnt;
    cnt.resize(del.size(),0);
    ll mx = (ll)1e18 * 3;
    for(pair<ll,ll> u : del) {
        ll f = u.first;
        ll c = 0;
        ll nn = n;
        while(nn > 0) {
            c += nn / f;
            nn /= f;
        }
        mx = min(mx, c / u.second);
    }
    cout << mx;
}