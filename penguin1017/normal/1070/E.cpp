#include "bits/stdc++.h"
using namespace std;
#define N (int)2e5+2
long long p[N],p1[N];
int main()
{
    long long c,n,m,t,i,sum,d=1,sum1,j,j1,t1,d1,k;
    cin>>c;
    while(c--)
    {
        sum1=0;
        scanf("%lld%lld%lld",&n,&m,&t);
        t1=t/2;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&p[i]);
            p1[i]=p[i];
        }
        sort(p+1,p+1+n);
        d=1;
        sum=0;
        long long l=0,mid,r=n;//l 
        while(l<r)
        {
        	mid=r-(r-l)/2;
        	d1=p[mid];
            sum1=0;
            d1=p[mid];
            j1=j=mid;
            for(i=1;sum1<=t&&j;i++)
            {
                 if(p1[i]<=d1)
                 {
                    sum1+=p1[i];
                    j--;
                    if(((mid-1)%m+1)==j)sum1*=2;
                 }
            }
            //cout<<j<<' '<<sum1<<"??\n";
            if(!j&&sum1<=t)
			{
				l=mid;
				d=d1;
			}
            else r=mid-1;
        //cout<<l<<' '<<r<<"ok\n";
        }
        printf("%lld %lld\n",l,d);
    }
}