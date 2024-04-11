#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        LL ans[2]={0,0};
        rep(i,n)if((a[i]&1)!=(i&1))ans[i&1]+=a[i];
        if(ans[1]>ans[0])puts("Alice");
        else if(ans[0]>ans[1])puts("Bob");
        else puts("Tie");
    }
    return 0;
}