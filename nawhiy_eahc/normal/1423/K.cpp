#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[1000010];
int main()
{
    for(i=1;i++<1000000;)
    {
        if(!A[i])
        {
            for(j=2*i;j<=1000000;j+=i)
            {
                A[j]=1;
            }
        }
    }
    for(i=0;i++<1000000;)A[i]=1-A[i];
    for(i=0;i++<1000000;)A[i]+=A[i-1];
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        if(n==1)
        {
            puts("1");
            continue;
        }
        k=(int)ceil(sqrt(n+1));
        printf("%d\n", A[n]-A[k-1]+1);
    }
}