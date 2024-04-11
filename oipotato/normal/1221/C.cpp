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
        int c,m,x;scanf("%d%d%d",&c,&m,&x);
        printf("%d\n",min(min(c,m),(c+m+x)/3));
    }
    return 0;
}