#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int a,b;scanf("%d%d",&a,&b);
    int ans[3]={0,0,0};
    rep(i,6)if(abs(i-a)<abs(i-b))ans[0]++;else if(abs(i-a)==abs(i-b))ans[1]++;else ans[2]++;
    printf("%d %d %d\n",ans[0],ans[1],ans[2]);
    return 0;
}