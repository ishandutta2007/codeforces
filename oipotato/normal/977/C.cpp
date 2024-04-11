#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,k,a[200010];
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(!k)printf("%d\n",a[1]==1?-1:1);
    else printf("%d\n",k<n&&a[k]==a[k+1]?-1:a[k]);
    return 0;
}