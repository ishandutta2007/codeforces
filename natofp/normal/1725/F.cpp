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
#define mt make_tuple

using namespace std;

const int nax = 1e5 + 5;
ll L[nax];
ll R[nax];
int n, q;

ll ans[30];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> L[i] >> R[i];
    for(int b=0;b<30;b++){
        int mod = (1 << b);
        vector<pii> intervals;
        for(int i=1;i<=n;i++){
            if(R[i] - L[i] + 1 >= mod) intervals.pb(mp(0, mod - 1));
            else{
                int from = L[i] % mod;
                int to = R[i] % mod;
                if(from <= to) intervals.pb(mp(from, to));
                else{
                    intervals.pb(mp(from, mod - 1));
                    intervals.pb(mp(0, to));
                }
            }
        }
        vector<pii> ev;
        for(pii cur : intervals){
            ev.pb(mp(cur.st, 1));
            ev.pb(mp(cur.nd + 1, -1));
        }
        sort(ev.begin(), ev.end());
        int mx = 0;
        int act = 0;
        for(auto cur : ev){
            act += cur.nd;
            mx = max(mx, act);
        }
        ans[b] = mx;
    }
    cin >> q;
    while(q--){
        int w; cin >> w;
        int b = 0;
        while(!(w & (1 << b))) b++;
        cout << ans[b] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}