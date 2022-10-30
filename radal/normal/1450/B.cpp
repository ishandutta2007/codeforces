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
typedef pair<int,int> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
pll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k,mx = 0;
        cin >> n >> k;
        rep(i,0,n){
            cin >> a[i].X >> a[i].Y;
        }
        bool f = 0;
        rep(i,0,n){
            mx = 0;
            rep(j,0,n){
                mx = max(mx,abs(a[i].X-a[j].X)+abs(a[i].Y-a[j].Y));
            }
            if (mx <= k){
                f = 1;
                break;
            }
        }
        if (f){
            cout << 1 << endl;
        }
        else cout << -1 << endl;

    }
    return 0;
}