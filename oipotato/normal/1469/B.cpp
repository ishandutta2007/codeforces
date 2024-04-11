#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int work()
{
    int ans=0,sum=0,n;scanf("%d",&n);
    rep(i,n){int x;scanf("%d",&x);sum+=x;ans=max(ans,sum);}
    return ans;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        printf("%d\n",work()+work());
    }
    return 0;
}