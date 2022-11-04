#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int b[105];
int main()
{
    int n;
    scanf("%d",&n);
    int loc=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i])b[loc++]=i;
    }
    int ans=loc>0;
    for(int i=1;i<loc;i++)
    {
        if(b[i]-b[i-1]<=2)
            ans+=b[i]-b[i-1]-1;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}