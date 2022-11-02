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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e7+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int f[N],dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    string s,w;
    cin >> s;
    n = s.size();
    w = s+'#';
    reverse(s.begin(),s.end());
    w += s;
    reverse(s.begin(),s.end());
    int l,r=0;
    f[0] = 1;
    rep(i,1,2*n+1){
        if (w[0] != w[i]){
            f[i] = 0;
            continue;
        }
        if (r < i){
            int p = 0,q=i;
            while (q < 2*n+1 && w[p] == w[q]){
                p++;
                q++;
            }
            q--;
            p--;
            f[i] = q;
            r = f[i];
            l = i;
        }
        else{
            int j = i-l;
            if (f[j]+l < r){
                f[i] = f[j]+l;
                continue;
            }
            while (r < 2*n && w[r+1] == w[r-l]) r++;
            l = i;
            f[i] = r;
        }
    }
    int ans = 0;
    repr(i,2*n,n+1){
        if (f[i] != 2*n) continue;
        dp[i] = dp[i+(2*n-i+2)/2]+1;
        ans += dp[i];
    }
    cout << ans;
}