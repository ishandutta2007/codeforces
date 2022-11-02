#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int pos[100010];
int main()
{
    int n;scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);pos[x]=i;}
    int m;scanf("%d",&m);
    LL a=0,b=0;
    rep(i,m){int x;scanf("%d",&x);a+=pos[x];b+=n-pos[x]+1;}
    printf("%lld %lld\n",a,b);
    return 0;
}