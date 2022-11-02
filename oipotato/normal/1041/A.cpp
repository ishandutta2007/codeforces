#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,mn=(int)1e9+1,mx=0;
    scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);mn=min(mn,x);mx=max(mx,x);}
    printf("%d\n",mx-mn+1-n);
    return 0;
}