#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=2e2+30,inf = 1e18;
ll a[N],b[N],c[N],p[N];
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        rep (i,0,n){
            cin >> a[i];
        }
        rep (i,0,n){
            cin >> b[i];
        }
        rep (i,0,n){
            cin >> c[i];
        }
        p[0] = a[0];
        rep(i,1,n){
            if (a[i] == p[i-1]) p[i] = b[i];
            else p[i] = a[i];
         //   debug(p[i]);
        }
        if (p[n-1] == p[0]){
            bool f1=0,f2=0,f3=0;
            if (p[n-2] == b[n-1] || p[0] == b[n-1]) f2=1;             
            if (p[n-2] == a[n-1] || p[0] == a[n-1]) f1=1;
            if (p[n-2] == c[n-1] || p[0] == c[n-1]) f3=1;
            if (!f1) p[n-1] = a[n-1];
            if (!f2) p[n-1] = b[n-1];
            if (!f3) p[n-1] = c[n-1];
        }
        rep(i,0,n) cout << p[i] << ' ';
        cout << endl;
    }
    return 0;
}