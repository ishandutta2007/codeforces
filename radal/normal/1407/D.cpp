#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e9,sq = 65,maxm = 3e4+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int h[N],dp[N],L[N][2],R[N][2];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(dp,63,sizeof dp);
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> h[i];
    stack<int> st,st2;
    rep(i,1,n+1){
        while (!st.empty() && h[st.top()] < h[i]) st.pop();
        if (st.empty()) L[i][0] = 0;
        else L[i][0] = st.top();
        st.push(i);
        while (!st2.empty() && h[st2.top()] > h[i]) st2.pop();
        if (st2.empty()) L[i][1] = 0;
        else L[i][1] = st2.top();
        st2.push(i);
    }
    stack<int> st1,st3;
    repr(i,n,1){
        while (!st1.empty() && h[st1.top()] < h[i]) st1.pop();
        if (st1.empty()) R[i][0] = n+1;
        else R[i][0] = st1.top();
        st1.push(i);
        while (!st3.empty() && h[st3.top()] > h[i]) st3.pop();
        if (st3.empty()) R[i][1] = n+1;
        else R[i][1] = st3.top();
        st3.push(i);
    }
    dp[n] = 0;
    dp[L[n][0]] = 1;
    dp[L[n][1]] = 1;
    repr(i,n-1,0){
        dp[i] = min({dp[i],dp[R[i][0]]+1,dp[R[i][1]]+1});
        dp[L[i][0]] = min(dp[L[i][0]],dp[i]+1);
        dp[L[i][1]] = min(dp[L[i][1]],dp[i]+1);
    }
    cout << dp[1];
}