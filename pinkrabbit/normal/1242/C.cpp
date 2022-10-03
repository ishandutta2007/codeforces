#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MK 15
#define MN 5005
#define MS 75005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int ms,k,c[MK];
ll a[MK][MN],s[MK],ts;
map<ll,pii>mp;
inline int id(pii x){return x.fi*5000+x.se;}
int nxt[MS],deg[MS],vis[MS],que[MS],l,r;
int can[1<<MK],cid[1<<MK],dp[1<<MK],g[1<<MK];
ll Ans1[MK];int Ans2[MK];
int main(){
	scanf("%d",&k),ms=k*5000;
	F2(i,0,k){
		scanf("%d",&c[i]);
		F(j,1,c[i])scanf("%lld",&a[i][j]),s[i]+=a[i][j],mp[a[i][j]]=mkp(i,j);
		ts+=s[i];
	}
	if(ts%k)return puts("No"),0;
	ts/=k;
	F2(i,0,k)F(j,1,c[i]){
		ll nv=a[i][j]+ts-s[i];
		if(mp.find(nv)==mp.end())continue;
		int vid=id(mp[nv]);
		nxt[id(mkp(i,j))]=vid;
		++deg[vid];
	}
	l=1,r=0;
	F(u,1,ms)if(nxt[u]&&!deg[u])que[++r]=u;
	while(l<=r){
		int u=que[l++];
		if(!--deg[nxt[u]])que[++r]=nxt[u];
	}
	F(u,1,ms)if(nxt[u]&&deg[u]&&!vis[u]){
		static int kis[MK];
		F2(i,0,k)kis[i]=0;
		vis[u]=1,kis[(u-1)/5000]=1;
		int s=1<<((u-1)/5000),j=nxt[u],ok=1;
		while(j!=u){
			if(kis[(j-1)/5000])ok=0;
			vis[j]=1,kis[(j-1)/5000]=1;
			s|=1<<((j-1)/5000),j=nxt[j];
		}
		if(!ok)continue;
//		printf("s=%d\n",s);
		can[s]=1,cid[s]=u;
	}
	dp[0]=1;
	F2(s,1,1<<k)for(int t=s;t;--t&=s)if(can[t]&&dp[s^t])dp[s]=1,g[s]=t;
	if(!dp[(1<<k)-1])return puts("No"),0;
	puts("Yes");
	int s=(1<<k)-1;
	while(s){
		int t=g[s];
		int u=cid[t];
		Ans1[(u-1)/5000]=a[(u-1)/5000][(u-1)%5000+1];
		Ans2[(nxt[u]-1)/5000]=(u-1)/5000;
		int j=nxt[u];
		while(j!=u){
			Ans1[(j-1)/5000]=a[(j-1)/5000][(j-1)%5000+1];
			Ans2[(nxt[j]-1)/5000]=(j-1)/5000;
			j=nxt[j];
		}
		s^=t;
	}
	F2(i,0,k)printf("%lld %d\n",Ans1[i],Ans2[i]+1);
	return 0;
}