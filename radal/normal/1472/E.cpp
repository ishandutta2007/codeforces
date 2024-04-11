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
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
pll a[N];
vector<pll> pw[N],ph;
ll ans[N];
vector<pair<pll,int> > w;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        w.clear();
        rep(i,0,n){
            cin >> a[i].X >> a[i].Y;
            w.pb({{-a[i].X,-a[i].Y},i+1});
        }
        sort(w.begin(),w.end());
        ph.clear();
        ph.resize(n);
        ph[n-1] = {-w[n-1].X.Y,w[n-1].Y};
        repr(i,n-2,0){
            pll p = {-w[i].X.Y,w[i].Y};
            ph[i] = min(ph[i+1],p);
        }
        rep(i,0,n){
            pair<pll,int> p1 = {{-a[i].X+1,-inf},0},p2 = {{-a[i].Y+1,-inf},0};
            int ind  = lower_bound(w.begin(),w.end(),p1)-w.begin();
            int ind2 = lower_bound(w.begin(),w.end(),p2)-w.begin();
            if (ind == n){
                ans[i] = -1;
            }
            else{
                if (ph[ind].X >= a[i].Y) ans[i] = -1;
                else ans[i] = ph[ind].Y;
            }
            if (ans[i] == -1 && ind2 != n){
                if (ph[ind2].X < a[i].X){
                    ans[i] = ph[ind2].Y;
                }
            }
            cout << ans[i] << ' ' ;
        }

        cout << endl;

    }
    return 0;
}