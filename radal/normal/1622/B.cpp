#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 4e18+10,sq = 400;
inline int mkay(int a,ll b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k,int m){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%m;
        n = (1ll*n*n)%m;
        k >>= 1;
    }
    return c;
}
int a[N],ans[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        cin >> s;
        vector<pll> v1,v0;
        rep(i,0,n){
            if (s[i] == '1') v1.pb({a[i],i});
            else v0.pb({a[i],i});
        }
        sort(v1.begin(),v1.end());
        sort(v0.begin(),v0.end());
        rep(i,0,int(v0.size())){
            ans[v0[i].Y] = i+1;
        }
        rep(i,0,int(v1.size())){
            ans[v1[i].Y] = i+1+v0.size();
        }
        rep(i,0,n) cout << ans[i] << ' ';
        cout << endl;
    }
}