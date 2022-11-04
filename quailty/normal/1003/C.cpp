#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int a[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    double res=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=i;j<=n;j++)
        {
            sum+=a[j];
            if(j-i+1>=k)res=max(res,1.0*sum/(j-i+1));
        }
    }
    printf("%.12f\n",res);
    return 0;
}