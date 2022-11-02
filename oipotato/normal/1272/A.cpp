#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int a[4];
        rep(i,3)scanf("%d",&a[i]);
        sort(a+1,a+4);
        printf("%d\n",max(0,2*(a[3]-a[1]-2)));
    }
    return 0;
}