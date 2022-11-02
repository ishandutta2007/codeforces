#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    vector<int>ans;
    int n,now=0;
    scanf("%d",&n);
    rep(i,n)
    {
        int x;scanf("%d",&x);
        if(x==1)
        {
            if(now)ans.pb(now);
            now=0;
        }
        now++;
    }
    if(now)ans.pb(now);
    int cnt=ans.size();
    printf("%d\n",cnt);
    rep(i,cnt)printf("%d%c",ans[i-1]," \n"[i==cnt]);
    return 0;
}