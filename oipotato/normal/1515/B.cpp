#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        bool flag=0;
        if(n%2==0)
        {
            int sq=(int)sqrt(n/2);
            if(sq*sq==n/2)flag=1;
        }
        if(n%4==0)
        {
            int sq=(int)sqrt(n/4);
            if(sq*sq==n/4)flag=1;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}