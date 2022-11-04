#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN],vis[MAXN];
char p[MAXN],t[MAXN];
int main()
{
    scanf("%s%s",p+1,t+1);
    int n=strlen(p+1),s=strlen(t+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=n;
    while(l<r)
    {
        int m=(l+r+1)/2;
        for(int i=1;i<=m;i++)
            vis[a[i]]=1;
        int c=1;
        for(int i=1;i<=n;i++)
            if(c<=s && !vis[i])c+=(p[i]==t[c]);
        for(int i=1;i<=m;i++)
            vis[a[i]]=0;
        if(c>s)l=m;
        else r=m-1;
    }
    return 0*printf("%d",l);
}