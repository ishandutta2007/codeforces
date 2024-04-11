#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
int L[15],R[15];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&L[i],&R[i]);
    db res=0;
    for(int i=1;i<=n;i++)
        for(int j=L[i];j<=R[i];j++)
            for(int k=1;k<=n;k++)
            {
                if(k==i)continue;
                int t=j+(k>i);
                db tmp=1.0*(R[k]-max(L[k],min(R[k]+1,t))+1)/(R[k]-L[k]+1);
                for(int l=1;l<=n;l++)
                {
                    if(l==i || l==k)continue;
                    int m=j-(l<i);
                    tmp*=1.0*(min(R[l],max(m,L[l]-1))-L[l]+1)/(R[l]-L[l]+1);
                }
                res+=tmp*j/(R[i]-L[i]+1);
            }
    printf("%.12f",res);
    return 0;
}