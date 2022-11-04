#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
char s[MAXN*2];
int pre[MAXN*2];
int main()
{
    int n,a,b,T;
    scanf("%d%d%d%d",&n,&a,&b,&T);
    scanf("%s",s+1);
    for(int i=n+1;i<=2*n;i++)
        s[i]=s[i-n];
    for(int i=1;i<=2*n;i++)
        pre[i]=pre[i-1]+(s[i]=='w');
    int res=0;
    for(int i=n+1;i<=2*n;i++)
    {
        int now=(i-n-1)*a+(pre[i]-pre[n])*b+(i-n);
        if(now>T)break;
        int l=2,r=n+1;
        while(l<r)
        {
            int m=(l+r)>>1;
            int tot=(i-m)*a+(pre[n]-pre[m-1])*b+(n+1-m);
            if(now>T-tot)l=m+1;
            else r=m;
        }
        res=max(res,min(n,i-l+1));
    }
    for(int i=n+1;i>1;i--)
    {
        int now=(n+1-i)*a+(pre[n+1]-pre[i-1])*b+(n+2-i);
        if(now>T)break;
        int l=n+1,r=2*n;
        while(l<r)
        {
            int m=(l+r+1)>>1;
            int tot=(m-i)*a+(pre[m]-pre[n+1])*b+(m-n-1);
            if(now>T-tot)r=m-1;
            else l=m;
        }
        res=max(res,min(n,l-i+1));
    }
    printf("%d\n",res);
    return 0;
}