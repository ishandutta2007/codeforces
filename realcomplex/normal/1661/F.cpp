#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

ll x[N];

ll f(ll d, ll m){
    m ++ ;
    ll g = d / m;
    ll res = g * 1ll * g * 1ll * (m - d % m);
    res += (g + 1) * 1ll * (g + 1) * 1ll * (d % m);
    return res;
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    ll total = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> x[i];
        total += f(x[i] - x[i - 1], 0);
    }
    ll lim;
    cin >> lim;

    ll lf = 0ll;
    ll rf = (ll)1e18 + 10000;
    ll mid;
    ll lu, ru, md;
    ll dd;
    ll maxi;
    ll gg;
    ll res = 0;
    lf = 0ll;
    rf = (ll)1e18 + 1000;
    while(lf + 1 < rf){
        mid = (lf + rf) / 2;
        maxi = 0;
        for(int i = 1; i <= n; i ++ ){
            lu = -1ll;
            ru = x[i] - x[i - 1] + 1;
            while(lu + 1 < ru){
                md = (lu + ru) / 2;
                gg = f(x[i] - x[i - 1], md) - f(x[i] - x[i - 1], md + 1);
                if(gg >= mid){
                    lu = md;
                }
                else{
                    ru = md;
                }
            }
            maxi += f(x[i] - x[i - 1], ru) - f(x[i] - x[i - 1], 0);
        }
        if(total + maxi <= lim){
            lf = mid;
        }
        else{
            rf = mid;
        }
    }
    vector<ll> pq;
    for(int i = 1; i <= n; i ++ ){
        lu = -1ll;
        ru = x[i] - x[i - 1] + 1;
        while(lu + 1 < ru){
            md = (lu + ru) / 2;
            gg = f(x[i] - x[i - 1], md) - f(x[i] - x[i - 1], md + 1);
            if(gg >= lf){
                lu = md;
            }
            else{
                ru = md;
            }
        }
        res += ru;
        total += f(x[i] - x[i - 1], ru) - f(x[i] - x[i - 1], 0);
    }

    res -= (lim - total) / lf;
    cout << res << "\n";
    return 0;
}