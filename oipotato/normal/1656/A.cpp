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
        int a[200010];
        rep(i,n)scanf("%d",&a[i]);
        int mx=1,mn=1;
        rep(i,n)
        {
            if(a[mx]<a[i])mx=i;
            if(a[mn]>a[i])mn=i;
        }
        printf("%d %d\n",mx,mn);
    }
    return 0;
}