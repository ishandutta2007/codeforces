#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=2e2+30,mod = 1e9+7,inf=1e9+7;
ll a[N][N],b[N][N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        memset(b,0,sizeof b);
        cin >> n >> m;
        rep (i,0,n){
            rep (j,0,m) cin >> a[i][j];
        }
        rep(i,0,n){
            rep(j,0,m){
                if ((i+j)%2 != a[i][j]%2){
                    a[i][j]++;
                }
            }
        }
        rep(i,0,n){
            rep(j,0,m) cout << a[i][j] << ' ';
            cout << endl;
        }

    }
    return 0;
}