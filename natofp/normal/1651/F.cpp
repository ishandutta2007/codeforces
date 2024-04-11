#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
const int SQ = 250;
ll r[nax];
ll c[nax];
ll ans = 0;
int n, q;
vector<pll> Q;
ll growth[nax][SQ + 1];

ll grow(int lo, int hi, int bound){
    return growth[hi][bound] - growth[lo - 1][bound];
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i] >> r[i];
    cin >> q;
    for(int i=1;i<=q;i++){
        ll t, h; cin >> t >> h;
        Q.pb(mp(t, h));
    }
    for(int j=1;j<=SQ;j++){
        for(int i=1;i<=n;i++){
            growth[i][j] = growth[i - 1][j] + min(c[i], r[i] * j);
        }
    }
    stack<tuple<ll, ll, ll> > modified;
    const ll inf = 1e12 + 1e11;
    modified.push(make_tuple(n + 1, -inf, -1)); // pos, czas, bal
    for(int i=n;i>=1;i--){
        modified.push(make_tuple(i, -inf, 0));
    }
    for(int i=0;i<q;i++){
        ll t = Q[i].st;
        ll h = Q[i].nd;
        int gone = 0;
        while(h > 0){
            auto [pos, when, oldBalance] = modified.top();
            int lo = gone + 1;
            int hi = pos - 1;
            bool brute = (t - when) > SQ;
            if(lo <= hi){
                if(brute){
                    ll dif = t - when;
                    for(int i=lo;i<=hi;i++){
                        ll want = min(dif, c[i] / r[i] + 1);
                        ll balance = min(c[i], r[i] * want);
                        if(balance >= h){
                            balance -= h;
                            h = 0;
                            modified.push(make_tuple(i, t, balance));
                            break;
                        }
                        else{
                            h -= balance;
                        }
                    }
                }
                else{
                    ll dif = t - when;
                    ll all = grow(lo, hi, dif);
                    if(all < h){
                        h -= all;
                    }
                    else{
                        int L = lo;
                        int R = hi;
                        while(L + 1 < R){
                            int mid = (L + R) / 2;
                            ll pref = grow(lo, mid, dif);
                            if(pref >= h) R = mid;
                            else L = mid;
                        }
                        int odp = R;
                        for(int mid=L;mid<=R;mid++){
                            ll pref = grow(lo, mid, dif);
                            if(pref >= h) odp = min(odp, mid);
                        }
                        ll pref = grow(lo, odp, dif) - h;
                        h = 0;
                        modified.push(make_tuple(odp, t, pref));
                    }
                }
            }
            if(h == 0) break;
            gone = hi;
            if(gone == n){
                modified.pop();
                modified.push(make_tuple(n + 1, t, -1));
                break;
            }
            modified.pop();
            ll dif = t - when;
            dif = min(dif, c[pos] / r[pos] + 1);
            ll mam = min(c[pos], oldBalance + dif * r[pos]);
            if(mam >= h){
                mam -= h;
                h = 0;
                modified.push(make_tuple(pos, t, mam));
                break;
            }
            else{
                h -= mam;
                gone += 1;
                continue;
            }
        }
        ans += h;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}