#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
int p[MAXN],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    p[n]=p[n-1];
    int la=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==p[i-1])
        {
            int len=i-la;
            ans=max(ans,(len-1)/2);
            if(len%2==0)
            {
                for(int j=la,k=1;k<=len/2;j++,k++)
                    res[j]=p[la];
                for(int j=i-1,k=1;k<=len/2;j--,k++)
                    res[j]=p[i];
            }
            else
            {
                for(int j=la;j<i;j++)
                    res[j]=p[la];
            }
            la=i;
        }

    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
        printf("%d ",res[i]);
    return 0;
}