#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool notp[100010];
int prime[100010],tot;
int main()
{
    for(int i=2;i<=100000;i++)
    {
        if(i>2&&!notp[i])prime[++tot]=i;
        for(int j=1;(LL)j*i<=100000;j++)notp[i*j]=1;
    }
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int num=0;
        rep(i,tot)
        {
            for(;n%prime[i]==0;n/=prime[i],num++);
        }
        int cnt=0;
        for(;n%2==0;n/=2,cnt++);
        if(n>1)num++;
        if(cnt==1)puts(num!=1?"Ashishgup":"FastestFinger");
        else puts(num?"Ashishgup":"FastestFinger");
    }
    return 0;
}