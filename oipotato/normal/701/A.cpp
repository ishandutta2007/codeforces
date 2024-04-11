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
    // for(scanf("%d",&T);T--;)
    {
        vector<int> c[110];
        int n;scanf("%d",&n);
        rep(i,100)c[i].clear();
        int sum=0;
        rep(i,n){int x;scanf("%d",&x);c[x].pb(i);sum+=x;}
        sum/=n/2;
        rep(i,100)for(;c[i].size();printf("%d ",c[i].back()),c[i].pop_back(),printf("%d\n",c[sum-i].back()),c[sum-i].pop_back());
    }
    return 0;
}