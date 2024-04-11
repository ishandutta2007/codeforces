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
typedef pair<int,int> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        bool f = 1;
        cin >> n;
        rep(i,1,n+1){
            cin >> a[i];
            if(a[i] != i) f = 0;
        }
        if (f){
            cout << 0 << endl;
            continue;
        }
        if (a[1] == 1 || a[n] == n){
            cout << 1 << endl;
            continue;
        }
        cout << ((a[1] != n || a[n] != 1) ? 2 : 3) << endl;
    }
    return 0;
}