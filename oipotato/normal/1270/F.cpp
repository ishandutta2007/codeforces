#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;i++)
#define x1 fuckcjb
#define y1 fucksub
#define x2 fuckjtjl
#define y2 fucksf
const int MAGIC=450;
const int N=200010;
const int LEN=MAGIC*N+N;
char s[N];
int cnt[LEN],a[N],c[N],nxt[N],n,sum[N];
long long ans;
bool vis[LEN];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,n)a[i]=s[i]-'0',sum[i]=sum[i-1]+a[i];
	rep(ti,MAGIC)
	{
		cnt[ti*n]=1;
		rep(i,n)c[i]=i-ti*sum[i]+ti*n;
		rep(i,n)cnt[c[i]]++;
		rep(i,n)if(!vis[c[i]])ans+=1ll*cnt[c[i]]*(cnt[c[i]]-1)/2,vis[c[i]]=1;
		rep(i,n)cnt[c[i]]=vis[c[i]]=0;
		cnt[ti*n]=0;
	}
	int last=n+1;nxt[n+1]=n+1;
	for(int i=n;i;i--){if(a[i])last=i;nxt[i]=last;}
	rep(i,n)
	{
		int now=nxt[i],cc=1;
		for(;i+1ll*cc*MAGIC-1<=n&&now<=n;)
		{
			int L=(now-i)/cc,R=(nxt[now+1]-i)/cc;
			//printf("%d %d %d %d %d\n",i,now,cc,L,R);
			ans+=max(0,R-max(MAGIC,L));
			now=nxt[now+1];cc++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}