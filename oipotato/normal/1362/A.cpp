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
        LL a,b;scanf("%lld%lld",&a,&b);
        if(a<b)swap(a,b);
        if(a%b)puts("-1");
        else
        {
            LL tmp=a/b;
            if((tmp&-tmp)!=tmp)puts("-1");
            else
            {
                int x=0;
                for(;tmp>1;x++,tmp>>=1);
                printf("%d\n",x/3+(x%3>0));
            }
        }
    }
    return 0;
}