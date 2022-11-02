#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,k,ans=-(int)1e9;
    scanf("%d%d",&n,&k);
    rep(i,n){int f,t;scanf("%d%d",&f,&t);ans=max(ans,f+min(0,k-t));}
    printf("%d\n",ans);
    return 0;
}