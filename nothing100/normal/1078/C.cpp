#include<bits/stdc++.h>
#define mo 998244353
#define LL long long
using namespace std;
int dp[3][300030],n;
vector<int> edge[300030];
void get(int x,int y){
    dp[0][x]=1;
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y){
        get(edge[x][i],x);
        int tmp[3];
        for (int j=0;j<3;j++){
            tmp[j]=dp[j][x];
            dp[j][x]=0;
        }
        //011>1,2>1 
        dp[1][x]=(dp[1][x]+1LL*tmp[0]*dp[0][edge[x][i]])%mo;
        dp[0][x]=(dp[0][x]+1LL*tmp[0]*dp[0][edge[x][i]])%mo;
        dp[0][x]=(dp[0][x]+1LL*tmp[0]*dp[1][edge[x][i]])%mo;
        dp[2][x]=(dp[2][x]+1LL*tmp[0]*dp[1][edge[x][i]])%mo;
        dp[1][x]=(dp[1][x]+1LL*tmp[0]*dp[2][edge[x][i]])%mo;
        dp[1][x]=(dp[1][x]+1LL*tmp[1]*dp[0][edge[x][i]])%mo;
        dp[1][x]=(dp[1][x]+2LL*tmp[1]*dp[1][edge[x][i]])%mo;
        dp[1][x]=(dp[1][x]+1LL*tmp[2]*dp[0][edge[x][i]])%mo;
        dp[2][x]=(dp[2][x]+1LL*tmp[2]*dp[0][edge[x][i]])%mo;
        dp[2][x]=(dp[2][x]+2LL*tmp[2]*dp[1][edge[x][i]])%mo;
        dp[1][x]=(dp[1][x]+1LL*tmp[2]*dp[2][edge[x][i]])%mo;
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        edge[o].push_back(p);
        edge[p].push_back(o);
    }
    get(1,0);
    printf("%d\n",(dp[0][1]+dp[1][1])%mo);
}