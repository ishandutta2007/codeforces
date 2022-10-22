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
const int INF = 1e18, MAXN = 2e5+20, MOD=998244353;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    vvi dp(n,vi(n,INF)), in(n,vi(n));
    loop(i,0,n) dp[i][i]=1, in[i][i]=a[i];
    loop(k,1,n){
        loop(i,0,n-k){
            int j = i+k;
            dp[i][j] = j-i+1;
            loop(x,i,j){
                chkmin(dp[i][j], dp[i][x]+dp[x+1][j]);
                if (dp[i][x]==1 && dp[x+1][j]==1 && in[i][x]==in[x+1][j]){
                    dp[i][j]=1; in[i][j] = in[i][x]+1;
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
5
4 3 2 2 3



*/