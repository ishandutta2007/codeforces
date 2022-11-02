#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010],b[100010],n;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int l,r;scanf("%d%d",&l,&r);
        puts(l*2>r?"YES":"NO");
    }
    return 0;
}