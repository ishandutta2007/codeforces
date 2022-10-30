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
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
int a[N],b[N],c[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep (i,0,n) cin >> a[i];
    rep(i,0,n-1) cin >> b[i];
    rep(i,0,n-2) cin >> c[i];
    sort(a,a+n);
    sort(b,b+n-1);
    sort(c,c+n-2);
    rep(i,0,n-1){
        if (b[i] != a[i]){
            cout << a[i] << endl;
            break;
        }
        if (i == n-2){
            cout << a[n-1] << endl;
            break;
        }
    }
    rep(i,0,n-2){
        if (b[i] != c[i]){
            cout << b[i] << endl;
            break;
        }
        if (i == n-3){
            cout << b[n-2] << endl;
            break;
        }
    }
    return 0;
}