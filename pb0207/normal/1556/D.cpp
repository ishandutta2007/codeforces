#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n,k,a[N];

int ans[N];

int OR(int i,int j)
{
    printf("or %lld %lld\n",i,j);
    fflush(stdout);
    // return ans[i]|ans[j];
    int ret=0;
    scanf("%lld",&ret);
    return ret;
}

int AND(int i,int j)
{
    printf("and %lld %lld\n",i,j);
    fflush(stdout);
    // return ans[i]&ans[j];
    int ret=0;
    scanf("%lld",&ret);
    return ret;
}

int b[N];

void get(int n)
{
    assert(n&1);
    int s=0;
    for(int i=1;i<n;i++)
        b[i]=OR(i,i+1)+AND(i,i+1),s+=b[i];
    b[n]=OR(n,1)+AND(n,1),s+=b[n];
    s/=2;
    a[1]=s;
    for(int i=2;i<=n;i+=2)
        a[1]-=b[i];
    for(int i=2;i<=n;i++)
        a[i]=b[i-1]-a[i-1];
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    // for(int i=1;i<=n;i++)
    //     scanf("%lld",&ans[i]);
    if(n%2==0)
    {
        get(n-1);
        int sum=OR(1,n)+AND(1,n);
        a[n]=sum-a[1];
    }
    else
        get(n);
    // for(int i=1;i<=n;i++)
    //     printf("%lld\n",a[i]);
    sort(a+1,a+n+1);
    printf("finish %lld\n",a[k]);
    fflush(stdout);
}