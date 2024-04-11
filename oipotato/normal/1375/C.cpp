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
        rep(i,n)scanf("%d",&a[i]);
        puts(a[1]<a[n]?"YES":"NO");
    }
    return 0;
}