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
        int a,b;scanf("%d%d",&a,&b);
        int base=0;
        if(b==1)b++,base++;
        int ans=0;
        for(int i=a;i;i/=b,ans++);
        rep(i,20)
        {
            b++;
            int tans=i;
            for(int i=a;i;i/=b,tans++);
            ans=min(ans,tans);
        }
        printf("%d\n",ans+base);
    }
    return 0;
}