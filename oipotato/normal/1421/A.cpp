#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int c[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",a+b-2*(a&b));
    }
    return 0;
}