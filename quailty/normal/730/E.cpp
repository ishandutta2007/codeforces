#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN],d[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&d[i]);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int now=0;
            if(a[i]<a[j])
            {
                int tmp=0;
                if(a[i]+d[i]>=a[j])
                {
                    tmp++;
                    if(a[i]+d[i]<a[j]+d[j])tmp++;
                }
                else if(a[i]+d[i]>=a[j]+d[j])tmp++;
                now=max(now,tmp);
                tmp=0;
                if(a[i]>=a[j]+d[j])
                {
                    tmp++;
                    if(a[i]+d[i]<a[j]+d[j])tmp++;
                }
                else if(a[i]+d[i]>=a[j]+d[j])tmp++;
                now=max(now,tmp);
            }
            else
            {
                int tmp=0;
                if(a[i]+d[i]<a[j])
                {
                    tmp++;
                    if(a[i]+d[i]>=a[j]+d[j])tmp++;
                }
                else if(a[i]+d[i]<a[j]+d[j])tmp++;
                now=max(now,tmp);
                tmp=0;
                if(a[i]<a[j]+d[j])
                {
                    tmp++;
                    if(a[i]+d[i]>=a[j]+d[j])tmp++;
                }
                else if(a[i]+d[i]<a[j]+d[j])tmp++;
                now=max(now,tmp);
            }
            res+=now;
        }
    return 0*printf("%d\n",res);
}