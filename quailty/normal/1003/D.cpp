#include<bits/stdc++.h>
using namespace std;
int cnt[35];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        int t=-1;
        while(a)a>>=1,t++;
        cnt[t]++;
    }
    while(q--)
    {
        int b;
        scanf("%d",&b);
        int res=0;
        for(int i=29;i>=0;i--)
        {
            int c=min(b/(1<<i),cnt[i]);
            res+=c;
            b-=c*(1<<i);
        }
        printf("%d\n",(b==0 ? res : -1));
    }
    return 0;
}