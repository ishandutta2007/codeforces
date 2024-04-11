#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%lld%lld",&n,&k);
        int l=1,r=2000000000;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(m-m/n<k)l=m+1;
            else r=m;
        }
        printf("%d\n",l);
    }
    return 0;
}