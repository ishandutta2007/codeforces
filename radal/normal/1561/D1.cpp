#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
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
const long long int N=4e6+20,mod = 1e9+7,inf=1e9;
vector<int> tajz[N];
int dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    while (T--){
        int n,m;
        cin >> n >> m;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 2; 2*i <= n; i++) dp[2*i]++;
        rep(i,3,n+1){
            dp[i] += (2*dp[i-1]+1)%m;
            dp[i] %= m;
            for (int j = 2; j*i <=n; j++){
                dp[j*i] = (dp[j*i]+(-dp[i-1]+dp[i]+m)%m)%m;
            }
        }
        cout << dp[n];
    }
}