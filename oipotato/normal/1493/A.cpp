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
        int n,k;
        scanf("%d%d",&n,&k);
        vector<int>ans;ans.clear();
        for(int i=(k+1)/2;i<=n;i++)if(i!=k)ans.pb(i);
        int cnt=ans.size();
        printf("%d\n",cnt);
        rep(i,cnt)printf("%d%c",ans[i-1]," \n"[i==cnt]);
    }
    return 0;
}