#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int ty[45];
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    char s[15];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if((int)strlen(s)==4)ty[i]=0;
        else ty[i]=1;
    }
    ll now=0,res=0;
    for(int i=n-1;i>=0;i--)
    {
        res+=(2*now+ty[i])*p/2;
        now=now<<1|ty[i];
    }
    printf("%I64d",res);
    return 0;
}