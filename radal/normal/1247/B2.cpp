#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+20,mod = 1e9+7,inf=1e12,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int a[N];
pll cnt[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,d,k;
        cin >> n >> k >> d;
        rep(i,0,n){
            cin >> a[i];
        }
        int mx = 0;
        int t = 0;
        rep(i,0,d){
            if (cnt[a[i]].Y == T) cnt[a[i]].X++;
            else{
                cnt[a[i]] = {1,T};
            }
            if (cnt[a[i]].X == 1) mx++;
        }
        t = mx;
        rep(i,d,n){
            cnt[a[i-d]].X--;
            if (cnt[a[i-d]].X == 0) t--;
            if (cnt[a[i]].Y == T) cnt[a[i]].X++;
            else cnt[a[i]] = {1,T};
            if (cnt[a[i]].X == 1) t++;
            mx = min(mx,t);
        }
        cout << mx << endl;
    }
    return 0;
}