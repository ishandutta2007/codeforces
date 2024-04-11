#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int c[1010],n;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)scanf("%d",&c[i]);
        int l=0,r=n+1,round=0,last=0,a=0,b=0;
        for(;l<r-1;)
        {
            round++;
            if(round%2==1)
            {
                int now=0;
                for(;l<r-1&&now<=last;now+=c[++l]);
                last=now;
                a+=now;
            }
            else
            {
                int now=0;
                for(;l<r-1&&now<=last;now+=c[--r]);
                last=now;
                b+=now;
            }
        }
        printf("%d %d %d\n",round,a,b);
    }
    return 0;
}