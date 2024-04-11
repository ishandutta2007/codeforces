#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,m,s[110],a[110],ans=0;
    scanf("%d%d",&n,&m);
    rep(i,m+1)s[i-1]=0;
    rep(i,n){int l,r;scanf("%d%d",&l,&r);s[l]++;s[r+1]--;}
    rep(i,m)s[i]+=s[i-1];
    rep(i,m)if(!s[i])a[++ans]=i;
    printf("%d\n",ans);
    rep(i,ans)printf("%d%c",a[i]," \n"[i==ans]);
    return 0;
}