#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e9+10,sq = 32000;
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
vector<int> ve[N];
int a[N],sz[N],ls[N];
ll sum[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1; 
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,0,n) cin >> a[i];
        rep(i,0,m){
            ve[i].clear();
            sum[i] = 0;
            cin >> sz[i];
            rep(j,0,sz[i]){
                int x;
                cin >> x;
                sum[i] += x;
                ve[i].pb(x);
            }
        }
        vector<pair<ld,int> > g;
        vector<int> z;
        sort(a,a+n);
        rep(i,0,n) g.pb({a[i],m+1});
        rep(i,0,m) g.pb({ld(sum[i])/sz[i],i});
        sort(g.begin(),g.end());
        int cur = 0,l = -1,r2 = n+m;
        bool fl = 0;
        repr(i,n+m-1,0){
            if (g[i].Y >= m){
                cur++;
                continue;
            }
            else{
                cur--;
                ls[g[i].Y] = cur;
                if (cur < -1){
                    fl = 1;
                    break;
                }
                if (cur == -1){
                    l = i;
                    if (r2 == n+m) r2 = i;
                }
                else if (!cur){
                    z.pb(i);
                }
            }
        }
        sort(z.begin(),z.end());
        if (fl){
            rep(i,0,m){
                rep(j,0,sz[i]) cout << 0;
            }
            cout << endl;
            continue;
        }
        rep(i,0,m){
            rep(j,0,sz[i]){
                ld d2 = ld(sum[i]-ve[i][j])/(sz[i]-1),d = ld(sum[i])/sz[i];
                pair<ld,int> p1 = {d,i},p2 = {d2,i};
                int ind = lower_bound(g.begin(),g.end(),p1)-g.begin(),ind2 = lower_bound(g.begin(),g.end(),p2)-g.begin();
                if (d2 > g[n+m-1].X){
                    cout << 0;
                    continue;
                }
                if ((d2 > d && g[ind2].Y < m && ls[g[ind2].Y] <= 0) || (d2 <= d && g[ind2].Y < m && ls[g[ind2].Y] == -1)){
                    cout << 0;
                    continue;
                }
                if ((r2 != n+m && ind < r2) || (l != -1 && ind2 >= l)){
                    cout << 0;
                    continue;
                }
                if (d2 <= d){
                    cout << 1;
                    continue;
                }
                if (z.empty() || z.back() <= ind){
                    cout << 1;
                    continue;
                }
                int x =*(upper_bound(z.begin(),z.end(),ind));
                if (x < ind2){
                    cout << 0;
                    continue;
                }
                cout << 1;

            }
        }
        cout << endl;
    }
    return 0 ;
}