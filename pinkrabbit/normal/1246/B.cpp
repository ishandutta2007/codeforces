#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define MP 10005
#define MS 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int ip[MN],p[MP],g[MN],pc;
void sieve(int n){
	for(int i=2;i<=n;++i){
		if(!ip[i])p[++pc]=i,g[i]=i;
		for(int j=1;j<=pc&&i*p[j]<=n;++j){
			ip[i*p[j]]=1;
			g[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int n,k,a[MN];
int sum[MS],id[MN][18],cnt,nums;
map<int,int>nxt[MS];
int trans(int u,int x,int y,int t){
//	if(t==1)printf("(%d,%d)\n",x,y);
	if(u==-1)return-1;
	if(y>17)return -1;
	if(!id[x][y])id[x][y]=++cnt;
	int j=id[x][y];
	if(!nxt[u].count(j)){
		if(t)nxt[u][j]=++nums;
		else return-1;
	}
	return nxt[u][j];
}
ll ans;
int main(){
	sieve(100000);
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n){
		int x=a[i],lst=0,cnt=0,now=0,vnow=0;
		while(x!=1){
			if(g[x]!=lst){
				if(cnt%k)
					now=trans(now,lst,cnt%k,1),
					vnow=trans(vnow,lst,k-cnt%k,0);
				lst=g[x],cnt=0;
			}
			++cnt,x/=g[x];
		}
		if(lst&&cnt%k)
			now=trans(now,lst,cnt%k,1),
			vnow=trans(vnow,lst,k-cnt%k,0);
//		printf("%d %d\n",now,vnow);
		if(vnow!=-1)ans+=sum[vnow];
		++sum[now];
	}printf("%lld\n",ans);
	return 0;
}