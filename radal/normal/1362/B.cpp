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
typedef pair<ll,ll> pll;
const long long int N=2e6+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int a[N],b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        sort(a,a+n);
        bool F = 0;
        rep(j,1,1024){
            rep(i,0,n){
                b[i] = a[i]^j;
            }
            sort(b,b+n);
            bool f = 1;
            rep(i,0,n) if (a[i] != b[i]) f = 0;
            if (f){
                cout << j << endl;
                F = 1;
                break;
            }
        }
        if (!F) cout << -1 << endl;
    }
    return 0;
}