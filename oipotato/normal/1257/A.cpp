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
        int n,x,a,b;scanf("%d%d%d%d",&n,&x,&a,&b);
        printf("%d\n",min(n-1,abs(a-b)+x));
    }
    return 0;
}