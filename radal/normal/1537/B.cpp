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
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        ll s=0,u=0,v=0;
        pll a[4] = {{1,1},{1,m},{n,1},{n,m}};
        rep(i,0,4){
            pll p = a[i],p2;
            rep(j,0,4){
                p2 = a[j];
                ll s2 = abs(x-p.X)+abs(y-p.Y)+abs(x-p2.X)+abs(y-p2.Y)+abs(p.X-p2.X)+abs(p.Y-p2.Y);
                if (s2 > s){
                    s = s2;
                    u = i;
                    v = j;
                }
            }
        }
        cout << a[u].X << ' ' << a[u].Y << ' ' << a[v].X << ' ' << a[v].Y << endl;
    }
}