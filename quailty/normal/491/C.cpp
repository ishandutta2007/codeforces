#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000005;
const int MAXK=55;
const int INF=0X3f3f3f3f;
char s[MAXN],t[MAXN],c[2*MAXK];
int ans[MAXK];
inline void build()
{
    for(int i=0;i<26;i++)c[i]=i+'a';
    for(int i=0;i<26;i++)c[i+26]=i+'A';
}
inline int get(char t)
{
    if(t>='a' && t<='z')return t-'a';
    else return t-'A'+26;
}
int g[MAXK][MAXK];
int linker[MAXK],lx[MAXK],ly[MAXK];
int slack[MAXK];
bool visx[MAXK],visy[MAXK];
bool DFS(int x,int ny)
{
    visx[x]=1;
    for(int y=0;y<ny;y++)
    {
        if(visy[y])continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        if(tmp==0)
        {
            visy[y]=1;
            if(linker[y]==-1 || DFS(linker[y],ny))
            {
                linker[y]=x;
                return 1;
            }
        }
        else if(slack[y]>tmp)
            slack[y]=tmp;
    }
    return 0;
}
int KM(int nx,int ny)
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<nx;i++)
    {
        lx[i]=-INF;
        for(int j=0;j<ny;j++)
            if(g[i][j]>lx[i])
                lx[i]=g[i][j];
    }
    for(int x=0;x<nx;x++)
    {
        for(int i=0;i<ny;i++)
            slack[i]=INF;
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(DFS(x,ny))break;
            int d=INF;
            for(int i=0;i<ny;i++)
                if(!visy[i] && d>slack[i])
                    d=slack[i];
            for(int i=0;i<nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(int i=0;i<ny;i++)
            {
                if(visy[i])ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res=0;
    for(int i=0;i<ny;i++)
        if(linker[i]!=-1)
            res+=g[linker[i]][i];
    return res;
}
int main()
{
    build();
    int n,k;
    scanf("%d%d%s%s",&n,&k,s,t);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            g[get(s[j])][i]+=(get(t[j])==i);
        }
    }
    printf("%d\n",KM(k,k));
    for(int i=0;i<k;i++)ans[linker[i]]=i;
    for(int i=0;i<k;i++)printf("%c",c[ans[i]]);
    return 0;
}