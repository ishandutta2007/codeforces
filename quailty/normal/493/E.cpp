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
    ll t,a,b;
    scanf("%I64d%I64d%I64d",&t,&a,&b);
    if(t==1)
    {
        if(a==1)
            return 0*printf("%s",(b==1 ? "inf" : "0"));
        else
        {
            bool isok=0;
            ll p=1;
            while(p<=b/a)
            {
                p*=a;
                if(p==b)isok=1;
            }
            if(isok)return 0*printf("1");
        }
    }
    int cnt=0;
    ll p=0,q=1,r=b;
    while(r && cnt<100)
    {
        p+=r%a*q;
        r/=a;
        q*=t;
        cnt++;
    }
    return 0*printf("%d",(p==a)+(cnt>1 && a==b));
}