#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n,k,d[2];
        scanf("%lld%lld%lld%lld",&n,&k,&d[0],&d[1]);
        if(n%3)
        {
            printf("no\n");
            continue;
        }
        bool isok=0;
        for(int i=0;i<2;i++,d[0]=-d[0])
            for(int j=0;j<2;j++,d[1]=-d[1])
            {
                if((k-d[0]+d[1])%3)continue;
                ll x[3];
                x[1]=(k-d[0]+d[1])/3;
                x[0]=x[1]+d[0];
                x[2]=x[1]-d[1];
                bool flag=1;
                for(int i=0;i<3;i++)
                    flag&=(x[i]>=0 && x[i]<=n/3);
                isok|=flag;
            }
        printf("%s\n",(isok ? "yes" : "no"));
    }
    return 0;
}