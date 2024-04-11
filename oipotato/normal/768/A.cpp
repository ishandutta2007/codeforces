#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,a[100010];
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n;
    for(;l<=n&&a[l]==a[1];l++);
    for(;r&&a[r]==a[n];r--);
    printf("%d\n",max(0,r-l+1));
    return 0;
}