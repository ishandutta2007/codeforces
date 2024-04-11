#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
#define N 600000

const LL mod=1000000007;
LL n,a[N],fac[N],d[N],fa[N],S[N],T[N],cnt[N],L[N],R[N],tot;
vector<LL> g[N];
vector<pii> vec[N];

void gg(){
	puts("0");
	exit(0);
}

void dfs(LL u){
	d[u]=d[fa[u]]+1;
	for (LL v:g[u]){
		if (v!=fa[u]){
			fa[v]=u;
			dfs(v);
		}
	}
}

void sp(LL x,LL y){
	if (S[x]&&S[x]!=y) gg();
	S[x]=y;
}

void tp(LL x,LL y){
	if (T[x]&&T[x]!=y) gg();
	T[x]=y;
}

void add(LL x,LL i,LL j){
	if (!i){sp(x,j); return;}
	if (!j){tp(x,i); return;}
	++cnt[i];
	if (cnt[i]>2||cnt[j]>2) gg();
	vec[x].emplace_back(i,j);
}

int pd(int x){
	if (x==1||L[x]) return 0;
	--tot;
	for (int y=R[x];y;y=R[y]){
		if (y==x) gg();
		--tot;
	}
	return 1;
}

LL calc(LL x){
	for (auto p:vec[x]){
		LL i=p.first,j=p.second;
		if (R[i]&&R[i]!=j) gg();
		if (L[j]&&L[j]!=i) gg();
		R[i]=j; L[j]=i;
	}
	tot=g[x].size();
	LL num=pd(x);
	for (LL y:g[x]){
		if (fa[y]==x){
			num+=pd(y);
		}
	}
	if (tot) gg();
	if (L[S[x]]||R[T[x]]) gg();
	tot=g[x].size();
	bool flag=0;
	for (LL i=S[x];i;i=R[i]){
		--tot;
		flag|=i==T[x];
	}
	if (flag&&tot) gg();
	L[x]=R[x]=0;
	for (LL y:g[x]) L[y]=R[y]=0;
	return fac[max(num-(S[x]>0)-(T[x]>0),0LL)];
}

int main(){
	scanf("%lld",&n);
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	for (LL i=1;i<n;++i){
		LL x,y; scanf("%lld%lld",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
	}
	dfs(1);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	for (LL i=1;i<=n;++i){
		if (a[i]){
			if (a[i]==i) gg();
			LL x=a[i],y=i,ex=0,ey=0;
			while (x!=y){
				if (d[x]>=d[y]){
					add(x,ex,x);
					ex=x; x=fa[x];
				}
				else{
					add(y,y,ey);
					ey=y; y=fa[y];
				}
			}
			add(x,ex,ey);
		}
	}
	LL ans=1;
	for (LL i=1;i<=n;++i){
		(ans*=calc(i))%=mod;
	}
	printf("%lld\n",ans);
	
	return 0;
}