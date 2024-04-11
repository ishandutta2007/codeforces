#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        if(n<=99)printf("%d\n",n%10);
        else
        {
            int mn=n%10;
            for(;n;mn=min(mn,n%10),n/=10);
            printf("%d\n",mn);
        }
    }
    return 0;
}