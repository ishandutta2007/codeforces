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
const long long int N=2e3+20,mod = 1e9+7,inf=1e12,maxq = 5e5+30,maxm = 3e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int a[N];
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        multiset<int> st;
        int n;
        vector<pll> ve;
        int mx= 0;
        cin >> n;
        rep(i,0,2*n){
            cin >> a[i];
            mx = max(mx,a[i]);
        }
        bool F = 0;
        sort(a,a+2*n);
        rep(i,0,2*n-1){
            st.clear();
            bool f = 0;
            ve.clear();
            ve.pb({a[i],a[2*n-1]});
            rep(i,0,2*n-1) st.insert(-a[i]);
            auto it = st.find(-a[i]);
            st.erase(it);
            mx = a[2*n-1];
            while (st.size()){
                int x = *(st.begin()) * (-1);
                st.erase(st.begin());
                auto it = st.find(-mx+x);
                if (it == st.end()){
                    f = 1;
                    break;
                }
                st.erase(it);
                ve.pb({x,mx-x});
                mx = x;
            }
            if (!f){
                F = 1;
                break;
            }
        }
        if (!F){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << ve[0].X + ve[0].Y << endl;
        rep(i,0,n) cout << ve[i].X << ' ' << ve[i].Y << endl;

    }
    return 0;
}