#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n&1)printf("1 %d %d\n",n/2,n/2);
        else if((n/2)&1)printf("2 %d %d\n",(n-2)/2,(n-2)/2);
        else printf("%d %d %d\n",n/2,n/4,n/4);
    }
    return 0;
}