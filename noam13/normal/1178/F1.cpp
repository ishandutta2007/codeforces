#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;
const int MOD = 998244353;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi c(n); loop(i,0,n) cin>>c[i];
    vi conv(n+1); loop(i,0,n) conv[c[i]]=i;
    vvi rmq(n,vi(n,INF)); loop(i,0,n) rmq[i][i]=c[i];
    loop(k,1,n) loop(i,0,n-k) rmq[i][i+k]=min(rmq[i][i+k-1], c[i+k]);
    vvi dp(n,vi(n,0)); loop(i,0,n) dp[i][i]=1;
    loop(k,1,n){
        loop(i,0,n-k){
            int j=i+k;
            //cout<<i<<" "<<j<<endl;
            int col = rmq[i][j];
            int pos = conv[col];
            int left=0,right=0;
            loop(bp,i,pos+1) left+=((bp>i?dp[i][bp-1]:1)*(bp==pos?1:dp[bp][pos-1]))%MOD, left%=MOD;
            loop(bp,pos,j+1) right+=((bp>pos?dp[pos+1][bp]:1)*(bp==j?1:dp[bp+1][j]))%MOD, right%=MOD;
            dp[i][j] = (left*right)%MOD;
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
/*
color a
cls
g++ ColorfulStrip.cpp -o a & a
3 3
1 2 3



*/