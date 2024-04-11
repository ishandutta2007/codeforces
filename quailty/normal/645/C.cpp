#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int t[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int cnt=0;
    for(int i=0;i<n;i++)
        if(s[i]=='0')t[cnt++]=i;
    int res=0x3f3f3f3f;
    for(int i=0;i+k<cnt;i++)
    {
        int l=i,r=i+k;
        while(l<r)
        {
            int m1=(2*l+r)/3;
            int m2=(l+2*r+2)/3;
            if(max(t[m1]-t[i],t[i+k]-t[m1])<max(t[m2]-t[i],t[i+k]-t[m2]))r=m2-1;
            else l=m1+1;
        }
        res=min(res,max(t[l]-t[i],t[i+k]-t[l]));
    }
    printf("%d\n",res);
    return 0;
}