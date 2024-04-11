#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=2e5+10;
ll sum[N],cnt[N],a[N];
ll binary(ll l, ll r, ll val){
    ll m;
    while (r-l > 1){
        m = (l+r)/2;
        if (sum[m] <= val){
            l = m;
            continue;
        }
        else{
            r = m;
        }
    }
    //debug(a[r]);
    return l;
}
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n,p,k;
        cin >> n >> p >> k;
        rep (i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        if (p < a[0]){
            cout << 0 << endl;
            continue;
        }
        if (n == 1 || p < a[1]){
            cout << 1 << endl;
            continue;
        }
        sum[0] = a[0];
        cnt[0] = 1;
        sum[1] = a[1];
        cnt[1] = 2;
        rep (i,2,n){
        //    debug(i); debug(cnt[i-1]);
            if (a[i] > p){
                cnt[i] = cnt[i-1];
                sum[i] = sum[i-1];
                continue;
            }
            if (p-a[i] < a[0]){
                if (cnt[i-1] == 2){
                    cnt[i] = 2;
                  //  cout << "rgbdsz";
                    sum[i] = sum[i-1];
                }
                else{
                    cnt[i] = cnt[i-1];
                    sum[i] = sum[i-1];
                }
                continue;
            }
            ll ind=binary(0,i-1,p-a[i]);
            if (cnt[ind]+2 > cnt[i-1]){
                cnt[i] = cnt[ind]+2;
                sum[i] = sum[ind]+a[i];
                continue;
            }
            if (cnt[ind]+2 == cnt[i-1]){
                cnt[i] = cnt[i-1];
                sum[i] = min(sum[i-1],sum[ind]+a[i]);
                continue;
            }
            cnt[i] = cnt[i-1];
            sum[i] = sum[i-1];
        }
        cout << cnt[n-1] << endl;
    }
    return 0;
}