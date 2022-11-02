#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1);
}
pll h[N];
int ans[N],sm[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int m,n,x;
        cin >> n >> m >> x;
        rep(i,0,n){
            cin >> h[i].X;
            h[i].Y = i;
        }
        rep(i,1,m+1) sm[i] = 0;
        sort(h,h+n);
        bool f=0;
        int n2=n;
        while (n >= m){
            if (f){
                repr(i,m,1){
                    n--;
                    sm[i] += h[n].X;
                    ans[h[n].Y] = i;
                }
                f = 0;
            }
            else{
                rep(i,1,m+1){
                    n--;
                    sm[i] += h[n].X;
                    ans[h[n].Y] = i;
                }
                f = 1;
            }
        }
        vector<pll>ve;
        rep(i,1,m+1) ve.pb({sm[i],i});
        sort(ve.begin(),ve.end());
        int i = 0;
        while (n){
            n--;
            sm[ve[i].Y]+=h[n].X;
            ans[h[n].Y] = ve[i].Y;
            i++;
        }
        sort(sm+1,sm+m+1);
        cout << ((sm[m]-sm[1] > x) ? "NO" : "YES") << endl;
        if (sm[m]-sm[1] <= x){
            rep(j,0,n2) cout << ans[j] << ' ';;
            cout << endl;
        }
    }
}