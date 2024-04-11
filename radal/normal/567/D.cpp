#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e12;
ll n,k,a,m;
ll x[N];
bool b[N];
bool check(ll ind){
    memset(b,0,sizeof b);
    rep(i,0,ind+1) b[x[i]]=1;
    ll cnt=0;
    rep(i,0,n){
        if (!b[i]){
            int t=0;
            while (i < n && !b[i]){
                i++;
                t++;
            }
      //      debug(t/(a+1)+1);
            if(i < n && b[i]) i--;
            cnt+=t/(a+1);
            if (t%(a+1) >= a) cnt++;
        }
    }
    //debug(cnt);
    if (cnt >= k) return 0;
    return 1;
}
ll binary(ll l,ll r){
    if (check(l)) return 1;
    ll mid;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (r < m) return r+1;
    else return -1;
}
int main(){
    cin >> n >> k >> a >> m;
    rep(i,0,m){
        cin >> x[i];
        x[i]--;
    }
    cout << binary(0,m);
   // cout << check(17);
    return 0;
}