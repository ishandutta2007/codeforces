#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll inf = (ll)1e18;
const ll N = (ll)5005;

bool dp1[N]; // i is clone and covered before = is possible?
ll dp2[N]; // i is clone and covered last = max time
ll ti[N], xi[N];

ll n;

ll ab(ll x){
    return max(x,-x);
}

void upd(ll it, ll lx, ll lt, ll lim){
    ll el = inf;
    ll er = -inf;
    ll cl,cr;
    ll pt;
    ll nx;
    ll dist;
    ll dif;
    for(ll j = it; j <= n; j ++ ){
        dist = ab(xi[j]-lx);
        if(el <= xi[j] && er >= xi[j]){
            dp1[j]=true;
        }
        if(ti[j]-lt >= dist){
            pt = max(lim,lt+dist);
            dp2[j]=max(dp2[j],ti[j]-pt);
            cl=xi[j];
            cr=xi[j];
            if(lt < lim){
                for(int lg = 32; lg >= 0 ; lg -- ){
                    nx = (cl-(1ll<<lg));
                    if(max(lim,lt+ab(lx-nx))+ab(xi[j]-nx) <= ti[j]){
                        cl = nx;
                    }
                }
                for(int lg = 32; lg >= 0 ; lg -- ){
                    nx = (cr+(1ll<<lg));
                    if(max(lim,lt+ab(lx-nx))+ab(xi[j]-nx) <= ti[j]){
                        cr = nx;
                    }
                }
            }
            else{
                dif = (ti[j]-lt-dist)/2;
                cl = min(xi[j],lx)-dif;
                cr = max(xi[j],lx)+dif;
            }
            er = max(er, cr);
            el = min(el, cl);
        }
        else{
            break;
        }
        lt = ti[j];
        lx = xi[j];
    }
}

int main(){
    fastIO;
    cin >> n;
    for(ll i = 0; i <= n; i ++ ){
        dp2[i]=-1;
    }
    dp2[0]=0;
    for(ll i = 1; i <= n; i ++ ){
        cin >> ti[i] >> xi[i];
    }
    ll las;
    ll pt;
    ll dist;
    ll el, er;
    ll ext;
    ll lx;
    for(ll i = 0 ; i <= n; i ++ ){
        if(dp2[i] != -1){
            upd(i + 1,xi[i],ti[i]-dp2[i],ti[i]);
        }
        if(dp1[i]){
            upd(i+1, xi[i-1],ti[i-1],ti[i]);
        }
    }
    if(dp1[n] || dp2[n]!=-1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}