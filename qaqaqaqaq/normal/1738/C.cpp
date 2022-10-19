#include<bits/stdc++.h>

using namespace std;


const int N=107;
int n;
int a[N];
int dp[N][N][2][2];
int solve(int x,int y,int k,int now){
    if (x==0&&y==0) return now^1;
    if (dp[x][y][k][now]!=-1) return dp[x][y][k][now];
    if (k==0){
        bool ok=0;
        if (x) ok|=solve(x-1,y,k^1,now^1);
        if (y) ok|=solve(x,y-1,k^1,now);
        return dp[x][y][k][now]=ok;
    }
    bool ok=1;
    if (x) ok&=solve(x-1,y,k^1,now);
    if (y) ok&=solve(x,y-1,k^1,now);
    return dp[x][y][k][now]=ok;
}
signed main(){
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<n;++i) cin>>a[i];
        int odd=0, even=0;
        for (int i=0;i<n;++i) if (a[i]&1) odd++; else even++;
        if (solve(odd,even,0,0)) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}