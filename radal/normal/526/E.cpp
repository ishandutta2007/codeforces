#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 1e6+20,mod = 1e9+7,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
ll a[N],r[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,0,n){
        cin >> a[i];
     /*   if (n == 918101 && a[i] != 1184){
            cout << " i : " << i << "  " << a[i] << endl;
            return 0;
        }*/
    }
    while (q--){
        ll k;
        cin >> k;
        ll sm = a[0];
        ll j = 0;
        rep(i,1,n){
            if (sm + a[i] > k)
                break;
            j++;
            sm += a[j];
        }
        r[0] = j;
        ll st = 0,t = r[0]+1;
        if (t != n && a[n-1]+sm <= k) t = inf;
        rep(i,1,n){
            sm -= a[i-1];
            if (j == i-1){
                j = i;
                sm = a[i];
            }
            while ((j+1)%n != i && sm + a[(j+1)%n] <= k){
                j++;
                if (j == n) j = 0;
                sm += a[j];
            }
            r[i] = j;
            if (r[i] == i-1 || sm+a[i-1] > k){
                if (r[i] >= i && r[i]-i+1 < t){
                    t = r[i]-i+1;
                    st = i;
                }
                if (r[i] < i && r[i]+1+n-i < t){
                    t = n-i+r[i]+1;
                    st = i;
                }
            }
        }
        ll ans = inf;
        rep(i,st,st+t){
            ll ind = i%n;
            ll cnt = 0;
            ll j = ind;
            while (1){
                cnt++;
                if (j != ind && r[j] == r[ind]) break;
                j = r[j];
                j++;
                if (j == n) j = 0;
                if (r[ind] < ind && (j >= ind || j <= r[ind])) break;
                if (r[ind] >= ind && j >= ind && j <= r[ind]) break;
            }
            ans = min(ans,cnt);
        }
        cout << ans << endl;
        //cout << t << endl;

    }
}