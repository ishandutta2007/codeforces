#include <bits/stdc++.h>

using namespace std;
int n,k;
long long mod=998244353;
long long jeste[502][502],nije[502][502];
int main()
{
    scanf("%i %i",&n,&k);
    //n=500,k=1;
    for(int i=1;i<=n;i++)
    {
        jeste[i][n+1]=1;
        nije[i][n+1]=0;
    }
    for(int maxx=1;maxx<=n;maxx++)
    {
        for(int i=n;i>0;i--)
        {
            long long res1=0,res2=0;
            for(int j=1;j<=n-i+1&&j<=maxx;j++)
            {
                if(j==maxx)
                {
                    res1=(res1+jeste[maxx][i+j])%mod;
                    res2=(res2+jeste[maxx][i+j])%mod;
                }
                else
                {
                    res1=(res1+nije[maxx][i+j])%mod;
                    res2=(res2+jeste[maxx][i+j])%mod;
                }
            }
            jeste[maxx][i]=res2;
            nije[maxx][i]=res1;
        }
    }
    //printf("%lld",nije[1][1]);
    long long finale=0;
    for(int maxx=1;maxx<=n;maxx++)
    {
        int d=k/maxx;
        long long nacini=nije[maxx][1];
        nacini=(nacini*2)%mod;
        //printf("nacini da se postavi kada je maxx:%i : %i\n",maxx,nacini);
        if(k%maxx==0)
        {
            d--;
        }
        d=min(d,n);
        //printf("d: %i\n",d);
        for(int i=1;i<=d;i++)
        {
            finale=(finale+nacini*nije[i][1])%mod;
        }
    }
    printf("%I64d\n",finale);
    return 0;
}