#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 5005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1e6 + 500;

int fr = -1,sol = 1;
char lst,c,s[N];
int n,cnt,dp[N][N];

int f(int i,int in){
    if(i == n) return 1;
    if(dp[i][in] != -1) return dp[i][in];
    int ret = 0;
    if(in > 0 && s[i-1] != 'f')
        ret = (ret + f(i,in - 1)) % MOD;
    if(s[i] == 'f')
        ret = (ret + f(i+1,in+1)) % MOD;
    if(s[i] == 's')
        ret = (ret + f(i+1,in)) % MOD;
    return dp[i][in] = ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf(" %c",s+i);
    printf("%d\n",f(0,0));
}