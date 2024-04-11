#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,bo[300100],next[300100],now[300100],t[300100],h[300100],ty,qk,x,num,ans;
int main()
{
    scanf("%d%d",&n,&m);
    bo[0]=1;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&ty,&x);
        if (ty==1)
        {
            h[++num]=x;
            if (now[x]!=0) next[now[x]]=num;
            else t[x]=num;
            now[x]=num;
            ans++;
        }
        else if (ty==2)
        {
            while (next[t[x]]!=0)
            {
                if (!bo[t[x]]) ans--;
                bo[t[x]]=1;
                t[x]=next[t[x]];
            }
            if (!bo[t[x]]) ans--;
            bo[t[x]]=1;
        }
        else
        {
            for (int j=qk+1;j<=x;j++)
            {
                if (!bo[j]) ans--;
                bo[j]=1;
            }
            qk=max(qk,x);
        }
        printf("%d\n",ans);
    }
    return 0;
}