#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int ap[MAXN],op[MAXN];
void work(int now,int cnt)
{
    for(int i=now<<1;i<=MAXN;(i<<=1),cnt++)
    {
        ap[i]++;
        op[i]+=cnt;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int in;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&in);
        int t=in,cnt=0;
        bool flag=1;
        while(t>0)
        {
            ap[t]++;
            op[t]+=cnt;
            cnt++;
            if(flag)work(t,cnt);
            if(t%2==0)flag=0;
            else flag=1;
            t/=2;
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=MAXN;i++)
        if(ap[i]==n)ans=min(ans,op[i]);
    printf("%d\n",ans);
    return 0;
}