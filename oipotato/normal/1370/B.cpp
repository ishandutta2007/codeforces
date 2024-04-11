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
        int n;
        vector<int>a[2];a[0].clear();a[1].clear();
        scanf("%d",&n);
        rep(i,2*n){int x;scanf("%d",&x);a[x&1].pb(i);}
        if(a[1].size()&1)a[1].pop_back(),a[0].pop_back();
        else if(a[1].size())a[1].pop_back(),a[1].pop_back();
        else a[0].pop_back(),a[0].pop_back();
        int cnt=a[0].size();
        for(int i=0;i<cnt;i+=2)printf("%d %d\n",a[0][i],a[0][i+1]);
        cnt=a[1].size();
        for(int i=0;i<cnt;i+=2)printf("%d %d\n",a[1][i],a[1][i+1]);
    }
    return 0;
}