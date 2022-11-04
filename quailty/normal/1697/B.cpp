#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll p[MAXN];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
        p[i]+=p[i-1];
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",p[n-x+y]-p[n-x]);
    }
    return 0;
}