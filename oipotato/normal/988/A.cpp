#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,k;
bool vis[110];
vector<int>ans;
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,n)
    {
        int x;scanf("%d",&x);
        if(!vis[x])ans.pb(i);
        vis[x]=1;
    }
    int cnt=ans.size();
    if(cnt<k){puts("NO");return 0;}
    puts("YES");
    rep(i,k)printf("%d%c",ans[i-1]," \n"[i==k]);
    return 0;
}