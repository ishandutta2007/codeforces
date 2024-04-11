#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,sum=0;scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);sum+=x;}
    int ans=0;
    rep(i,5)if((sum+i)%(n+1)!=1)ans++;
    printf("%d\n",ans);
    return 0;
}