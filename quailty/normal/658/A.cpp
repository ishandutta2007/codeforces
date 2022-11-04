#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p[55],t[55];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    int res[2]={0,0},now[2]={0,0};
    for(int i=1;i<=n;i++)
        res[0]+=max(0,p[i]-c*(now[0]+=t[i]));
    for(int i=n;i>=1;i--)
        res[1]+=max(0,p[i]-c*(now[1]+=t[i]));
    if(res[0]>res[1])printf("Limak");
    else if(res[0]<res[1])printf("Radewoosh");
    else printf("Tie");
    return 0;
}