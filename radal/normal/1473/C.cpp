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
const long long int N=1e5+20,mod = 1e9+7,inf=1e16;
const long double eps = 0.0001;
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >>k;
        rep(i,1,k+1) a[i] = i;
     //   rep(i,k+1,n+1) a[i] = 2*k-i;
        reverse(a+2*k-n,a+k+1);
        rep(i,1,k+1) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}