#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN],b[MAXN],id[MAXN];
int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),w-=(b[i]=(a[i]+1)/2),id[i]=i;
    if(w<0)return 0*printf("-1");
    sort(id+1,id+n+1,[](int x,int y){return a[x]>a[y];});
    for(int i=1;i<=n;i++)
        while(w>0 && b[id[i]]<a[id[i]])
            b[id[i]]++,w--;
    if(w>0)return 0*printf("-1");
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    return 0;
}