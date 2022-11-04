#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXM=2000005;
int pi[MAXM],rub[MAXM];
void build()
{
    pi[1]=1;
    for(int i=2;i<=2000000;i++)
        if(!pi[i])
            if(i<=1500)
                for(int j=i*i;j<=2000000;j+=i)pi[j]=1;
    for(int i=1;i<=2000000;i++)
        pi[i]=pi[i-1]+(1-pi[i]);
    for(int i=1;i<=2000000;i++)
    {
        int t=i,tt=0;
        while(t)
        {
            tt=tt*10+t%10;
            t/=10;
        }
        if(tt==i)rub[i]=1;
    }
    for(int i=1;i<=2000000;i++)
        rub[i]+=rub[i-1];
}
int main()
{
    build();
    int p,q;
    scanf("%d%d",&p,&q);
    int ans=0;
    for(int i=1;i<=2000000;i++)
        if(q*pi[i]<=p*rub[i])ans=i;
    if(ans)printf("%d\n",ans);
    else printf("Palindromic tree is better than splay tree\n");
    return 0;
}