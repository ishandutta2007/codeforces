#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int cnt[N],ans[N];
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    vector<pair<pll,vector<int>>> ve;
    while (T--){
        ve.clear();
        int n,m;
        cin >> n >> m;
        rep(i,1,n+1) cnt[i] = 0;
        ve.resize(m);
        rep(i,0,m){
            cin >> ve[i].X.X;
            ve[i].X.Y = i;
            rep(j,0,ve[i].X.X){
                int val;
                cin >> val;
                ve[i].Y.pb(val);
            }
        }
        sort(ve.begin(),ve.end());
        bool f = 0;
        rep(i,0,m){
            int k = ve[i].X.X,mi = 1e9,ind = -1;;
            for (int j : ve[i].Y){
                if (mi > cnt[j]){
                    mi = cnt[j];
                    ind = j;
                }           
            }
            if (mi >= m/2+m%2){
                f = 1;
                break;
            }
            cnt[ind]++;
            ans[ve[i].X.Y] = ind;
        }
        if (f){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        rep(i,0,m) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}