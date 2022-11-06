#include <bits/stdc++.h>
using namespace std;

int r, g;
int h;
const int M = int(1e9) + 7;

int dp[2][200010];

int cnt(int s){
    if(s<0) return 0;
    int cur=1, bef=0;
    for(int i=1; i<=s; ++i) dp[bef][i]=0;
    dp[0][0]=1;
    for(int i=1; i<=h; ++i){
        for(int j=0; j<=s; ++j){
            dp[cur][j]=dp[bef][j];
            if(j>=i) dp[cur][j]=(dp[cur][j]+dp[bef][j-i])%M;
        }
        cur=bef; bef=1-cur;
    }
    int ret=0;
    for(int i=0; i<=s; ++i) ret+=dp[bef][i], ret%=M;
    return ret;
}

int main()
{
    cin >> r >> g;
    for(h=1; (h+1)*(h+2) <= 2*(g+r); ++h);
    cout << (cnt(r) - cnt(h*(h+1)/2 - g - 1) + M) % M << endl;
    return 0;
}