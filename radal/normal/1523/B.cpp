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
const long long int N=1e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 3e5+20;
ll poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (r*r)%mod*poww(n,k&1)%mod;
}
int a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1) cin >> a[i];
        vector<pair<int,pll>> ve;
        for (int i = 1; i<=n; i+=2){
            ve.pb({1,{i,i+1}});
            ve.pb({2,{i,i+1}});
            ve.pb({1,{i,i+1}});
            ve.pb({2,{i,i+1}});
            ve.pb({1,{i,i+1}});
            ve.pb({2,{i,i+1}});
        }
        cout << ve.size() << endl;
        for (auto u : ve) cout << u.X << ' ' << u.Y.X << ' ' << u.Y.Y << endl;
    }
    return 0;
}