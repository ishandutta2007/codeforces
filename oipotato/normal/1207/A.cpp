#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int b,p,f,h,c;scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
        if(h<c)swap(p,f),swap(h,c);
        int tmp=min(b/2,p);
        int ans=h*tmp;
        b-=2*tmp;
        tmp=min(b/2,f);
        printf("%d\n",ans+tmp*c);
    }
    return 0;
}