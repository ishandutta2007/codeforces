#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int ans[4]={0,1,1,0};
    int n;scanf("%d",&n);
    printf("%d\n",ans[n%4]);
    return 0;
}