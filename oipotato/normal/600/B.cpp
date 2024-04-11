#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,m,a[200010];
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    rep(i,m)
    {
        int x;scanf("%d",&x);
        printf("%d%c",upper_bound(a+1,a+n+1,x)-a-1," \n"[i==m]);
    }
    return 0;
}