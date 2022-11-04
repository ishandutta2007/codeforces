#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10005;
char s[MAXN],t[MAXN];
int main()
{
    scanf("%s",s);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        l--,r--;
        int tt=k%(r-l+1);
        for(int i=0;i<=r-l;i++)
            t[(tt+i)%(r-l+1)]=s[i+l];
        for(int i=l;i<=r;i++)
            s[i]=t[i-l];
    }
    printf("%s",s);
    return 0;
}