#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=500005;
const int MAXH=60;
vector<db>p[MAXN];
int fa[MAXN],stk[MAXH+5],top;
int main()
{
    int q,n=0;
    p[++n]=vector<db>(MAXH+1,1),p[n][0]=0;
    scanf("%d",&q);
    while(q--)
    {
        int ty,v;
        scanf("%d%d",&ty,&v);
        if(ty==1)
        {
            p[++n]=vector<db>(MAXH+1,1),p[n][0]=0;
            fa[n]=v;
            top=0;
            for(int i=n,j=0;i>0 && j<MAXH;i=fa[i],j++)
                stk[top++]=i;
            for(int i=top-1;i>1;i--)
                p[stk[i]][i]/=(1+p[stk[i-1]][i-1])/2;
            for(int i=1;i<top;i++)
                p[stk[i]][i]*=(1+p[stk[i-1]][i-1])/2;
        }
        else
        {
            db res=0;
            for(int i=0;i<MAXH;i++)
                res+=i*(p[v][i+1]-p[v][i]);
            printf("%.10f\n",res);
        }
    }
    return 0;
}