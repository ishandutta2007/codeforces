#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[100010];
int sum[100010];
int main()
{
    int n,q;scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    rep(i,n)sum[i]=sum[i-1]+s[i]-'a'+1;
    rep(i,q){int l,r;scanf("%d%d",&l,&r);printf("%d\n",sum[r]-sum[l-1]);}
    return 0;
}