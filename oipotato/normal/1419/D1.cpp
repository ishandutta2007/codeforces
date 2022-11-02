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
    printf("%d\n",(n-1)/2);
    rep(i,n)printf("%d%c",a[(i&1)?n/2+(i+1)/2:i/2]," \n"[i==n]);
    return 0;
}