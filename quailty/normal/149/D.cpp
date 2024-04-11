#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int root=0;
const int Mod=1000000007;
const int valid[4]={1,2,3,6};
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
    if(x<0)x+=Mod;
}
char s[705];
vector<int>e[705];
stack<int>stk;
int dp[705][9];
void dfs(int u)
{
    dp[u][0]=1;
    int tmp[9];
    for(int i=0,flag=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs(v);
        if(!flag)
        {
            for(int tk=(dp[u][0]=0);tk<4;tk++)
            {
                int k=valid[tk];
                dp[u][k]=dp[v][k];
            }
            flag=1;
        }
        else
        {
            for(int j=0;j<9;j++)tmp[j]=0;
            for(int j=0;j<9;j++)
                for(int tk=0;tk<4;tk++)
                {
                    int k=valid[tk];
                    int cl[2]={j/3,j%3},cr[2]={k/3,k%3};
                    if(cl[1]>0 && cr[0]>0 && cl[1]==cr[0])continue;
                    int p=cl[0]*3+cr[1];
                    add(tmp[p],1LL*dp[u][j]*dp[v][k]%Mod);
                }
            for(int j=0;j<9;j++)dp[u][j]=tmp[j];
        }
    }
    if(u!=root)
    {
        for(int j=0;j<9;j++)tmp[j]=0;
        for(int j=0;j<9;j++)
            for(int tk=0;tk<4;tk++)
            {
                int k=valid[tk];
                int ci[2]={j/3,j%3},co[2]={k/3,k%3};
                if((ci[0]>0 && co[0]>0 && ci[0]==co[0])
                || (ci[1]>0 && co[1]>0 && ci[1]==co[1]))continue;
                add(tmp[k],dp[u][j]);
            }
        for(int j=0;j<9;j++)dp[u][j]=tmp[j];
    }
}
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1),tot=0;
    s[0]='(',s[n+1]=')';
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(')
        {
            if(tot)e[stk.top()].push_back(tot);
            stk.push(tot++);
        }
        else stk.pop();
    }
    dfs(root);
    int res=0;
    for(int i=0;i<9;i++)
        add(res,dp[root][i]);
    printf("%d\n",res);
    return 0;
}