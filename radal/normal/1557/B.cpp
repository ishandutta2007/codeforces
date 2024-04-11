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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(int a,int k){
    if (k == 1) return a;
    if (!k) return 1;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
pll a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        rep(i,0,n){
            cin >> a[i].X;
            a[i].Y = i;
        }
        sort(a,a+n);
        int ans = 0;
        rep(i,0,n){
            ans++;
            while (i < n-1 && a[i+1].Y == a[i].Y+1) i++;
        }
        cout << ((ans <= k) ? "Yes" : "No") << endl;
    }
    return 0;
}