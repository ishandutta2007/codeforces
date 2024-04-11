#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=1e3+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll c[N][N],a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int k,n;
        cin >> n >> k;
        rep(i,0,n) cin >> a[i];
        sort(a,a+n);
        int p1= n-k,p2 = n-k;
        while (p1 < n-1 && a[p1+1] == a[p1]) p1++;
        while (p2 > 0 && a[p2-1] == a[p2]) p2--;
        rep(i,0,n+1) c[0][i] = 1;
        rep(i,1,k+1) rep(j,i,n+1) c[i][j] = (c[i][j-1]+c[i-1][j-1])%mod;
        //debug(c[2][4]);
       // debug(p);
        cout << c[p1-n+k+1][p1-p2+1] << endl;
    }
    return 0;
}