#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e3+30;
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        ll B,A;
        B = max(y,b-n);
        A = max(x,a-n);
        debug(A*max(b+n-a+A,y));
        debug(B*max(x,a+n-b+B));
        cout << min(A*max(b-n+a-A,y),B*max(x,a-n+b-B)) << endl;


    }
    return 0;
}