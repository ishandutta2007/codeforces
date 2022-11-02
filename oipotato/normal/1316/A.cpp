#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010],n;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m,sum=0;scanf("%d%d",&n,&m);
        rep(i,n){int x;scanf("%d",&x);sum+=x;}
        printf("%d\n",min(sum,m));
    }
    return 0;
}