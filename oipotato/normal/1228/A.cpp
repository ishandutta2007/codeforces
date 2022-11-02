#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[10];
void check(int x)
{
    int cnt=0;
    for(int i=x;i;a[++cnt]=i%10,i/=10);
    sort(a+1,a+cnt+1);
    rep(i,cnt-1)if(a[i]==a[i+1])return;
    printf("%d\n",x);
    exit(0);
}
int main()
{
    int l,r;scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)check(i);
    puts("-1");
    return 0;
}