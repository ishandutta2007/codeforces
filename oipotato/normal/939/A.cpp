#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,a[5010];
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,n)if(a[a[a[i]]]==i){puts("YES");return 0;}
    puts("NO");
    return 0;
}