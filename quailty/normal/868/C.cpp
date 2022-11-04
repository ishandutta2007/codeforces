#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[25];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int mask=0;
        for(int j=0;j<k;j++)
        {
            int t;
            scanf("%d",&t);
            mask=mask<<1|t;
        }
        cnt[mask]++;
    }
    if(cnt[0])return 0*printf("YES\n");
    for(int i=0;i<(1<<k);i++)
        for(int j=0;j<(1<<k);j++)
            if(!(i&j) && cnt[i] && cnt[j])
                return 0*printf("YES\n");
    return 0*printf("NO\n");
}