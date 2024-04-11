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
int a[6][N],n,cnt[30];
char s[N<<1];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)
        {
            rep(j,5)cnt[j]=0;
            scanf("%s",s+1);int len=strlen(s+1);
            rep(j,len)cnt[s[j]-'a'+1]++;
            rep(j,5)a[j][i]=2*cnt[j]-len;
        }
        rep(i,5)sort(a[i]+1,a[i]+n+1,greater<int>());
        int ans=0;
        rep(i,5)
        {
            int tans=0,now=0;
            rep(j,n)if(now+a[i][j]>0)tans++,now+=a[i][j];else break;
            ans=max(ans,tans);
        }
        printf("%d\n",ans);
    }
    return 0;
}