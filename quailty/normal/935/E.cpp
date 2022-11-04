#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
const int MAXO=105;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
int val[MAXN],mx[MAXN][MAXO],mi[MAXN][MAXO];
void dfs(int u,int t)
{
    for(int j=0;j<MAXO;j++)
        mx[u][j]=-INF,mi[u][j]=INF;
    if(val[u]>0)
    {
        mx[u][0]=mi[u][0]=val[u];
        return;
    }
    int l=e[u][0],r=e[u][1];
    dfs(l,t),dfs(r,t);
    for(int i=0;i<MAXO;i++)if(mx[l][i]>-INF)
        for(int j=0;i+j+1<MAXO;j++)if(mx[r][j]>-INF)
        {
            mx[u][i+j+t]=max(mx[u][i+j+t],mx[l][i]+mx[r][j]);
            mx[u][i+j+1-t]=max(mx[u][i+j+1-t],mx[l][i]-mi[r][j]);
            mi[u][i+j+t]=min(mi[u][i+j+t],mi[l][i]+mi[r][j]);
            mi[u][i+j+1-t]=min(mi[u][i+j+1-t],mi[l][i]-mx[r][j]);
        }
}
char str[MAXN];
int main()
{
    int P,M,n=0;
    scanf("%s%d%d",str,&P,&M);
    stack<int> stk;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='(')stk.push(++n);
        else if(str[i]==')')
        {
            int t=stk.top();
            stk.pop();
            if(!stk.empty())
                e[stk.top()].push_back(t);
        }
        else if(str[i]>='1' && str[i]<='9')
        {
            if(stk.empty())return 0*printf("%d\n",str[i]-'0');
            e[stk.top()].push_back(++n);
            val[n]=str[i]-'0';
        }
    }
    dfs(1,P<M);
    return 0*printf("%d\n",mx[1][min(P,M)]);
}