#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 300001;
int n;
int x[N];
int h[N];
int dp[N][3];
int solve(int pos,int last,int las){
    if(pos==n){
        return 1;
    }
    if(dp[pos][last]!=-1){
        return dp[pos][last];
    }
    if(las < x[pos] - h[pos]){
        return dp[pos][last] = max(1 + solve(pos+1,0,x[pos]) , solve(pos+1,1,x[pos]) );
    }
    else{
        int ans = solve(pos+1,1,x[pos]);
        if(x[pos+1]>x[pos]+h[pos]){
            ans = max(ans , 1 + solve(pos+1,2,x[pos]+h[pos]));
        }
        return dp[pos][last] = ans;
    }
}
int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i = 1;i<=n;++i){
        cin>>x[i]>>h[i];
    }
    if(n<=2){
        cout<<n;
        return 0;
    }
    int ans = 1 + solve(2,0,x[1]);
    cout<<ans;
}