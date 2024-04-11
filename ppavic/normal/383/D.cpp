#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 1e3 + 5;
const int M = 1e4 + 5;
const int MOD = 1e9 + 7;

int a[N];
int dp[N][M][3];
int n;

int  f(int i,int k,int fl){
    if(i == n && k == 0 && fl) return 1;
    if(i == n) return 0;
    if(dp[i][k][fl] != -1) return dp[i][k][fl];
    if(!fl){
        dp[i][k][fl] = (f(i+1,k,fl) + f(i+1,a[i],1)) % MOD;
    }
    if(fl == 1){
        dp[i][k][fl] =((f(i+1,k + a[i],fl) + f(i+1,abs(k - a[i]),fl)) % MOD + f(i+1,k,2)) % MOD;
    }
    if(fl == 2){
        dp[i][k][fl] = f(i+1,k,fl) % MOD;
    }
    return dp[i][k][fl];

}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    printf("%d\n",f(0,0,0)* 2 % MOD);
}