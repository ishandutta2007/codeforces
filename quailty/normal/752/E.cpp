#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXA=10000005;
ll cnt[MAXA];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll tot=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
        tot+=a;
    }
    if(tot<k)return 0*printf("-1");
    tot=n;
    int mx=MAXA-1;
    for(int i=1;i<MAXA;i++)
    {
        while(mx>=i && tot<k)
        {
            tot-=cnt[mx];
            for(int j=0;j<2;j++)
            {
                cnt[(mx+j)/2]+=cnt[mx];
                if((mx+j)/2>=i)tot+=cnt[mx];
            }
            cnt[mx--]=0;
        }
        if(mx<i)return 0*printf("%d",i-1);
        tot-=cnt[i];
    }
    return 0;
}