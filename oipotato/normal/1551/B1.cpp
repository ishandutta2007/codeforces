#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
vector<int>g[N];
int ans[N],p[N];
char s[N];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k=2;
        scanf("%s",s+1);n=strlen(s+1);
        rep(i,26)g[i].clear();
        rep(i,n){int x=s[i]-'a'+1;g[x].pb(i);}
        int cnt=0,ans=0;
        rep(i,26)
        {
            if(g[i].size()>=k)ans++;
            else for(auto j:g[i])p[++cnt]=j;
        }
        printf("%d\n",ans+cnt/2);
    }
    return 0;
}