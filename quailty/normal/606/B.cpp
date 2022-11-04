#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
bool vis[MAXN][MAXN];
char s[100005];
int main()
{
    int x[2],y[2];
    for(int i=0;i<2;i++)
        scanf("%d%d",&x[i],&y[i]);
    int tot=x[0]*y[0];
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        printf("%d ",!vis[x[1]][y[1]]);
        tot-=(!vis[x[1]][y[1]]);
        vis[x[1]][y[1]]=1;
        if(s[i]=='L')y[1]--;
        else if(s[i]=='R')y[1]++;
        else if(s[i]=='U')x[1]--;
        else x[1]++;
        x[1]=max(1,min(x[1],x[0]));
        y[1]=max(1,min(y[1],y[0]));
    }
    printf("%d\n",tot);
    return 0;
}