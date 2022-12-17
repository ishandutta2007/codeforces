#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5;
int n,m,p,q;
char s[maxn];
vector<pair<int,int>> g[maxn];
ll d[maxn];
const ll inf=9e18;
using pr=pair<ll,int>;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	p=read();
	q=read();
	for(int i=1;i<=n;i++) scanf("%s",s+m*(i-1)+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		int u=m*(i-1)+j;
		if(s[u]=='U'){
			if(i<n-1&&s[u+m*2]!='#') g[u+m*2].push_back({u,q});
			if(j>1&&s[u+m-1]!='#') g[u+m-1].push_back({u,p});
			if(j<m&&s[u+m+1]!='#') g[u+m+1].push_back({u,p});
		}
		else if(s[u]=='D'){
			if(i>2&&s[u-m*2]!='#') g[u-m*2].push_back({u,q});
			if(j>1&&s[u-m-1]!='#') g[u-m-1].push_back({u,p});
			if(j<m&&s[u-m+1]!='#') g[u-m+1].push_back({u,p});
		}
		else if(s[u]=='L'){
			if(j<m-1&&s[u+2]!='#') g[u+2].push_back({u,q});
			if(i>1&&s[u-m+1]!='#') g[u-m+1].push_back({u,p});
			if(i<n&&s[u+m+1]!='#') g[u+m+1].push_back({u,p});
		}
		else if(s[u]=='R'){
			if(j>2&&s[u-2]!='#') g[u-2].push_back({u,q});
			if(i>1&&s[u-m-1]!='#') g[u-m-1].push_back({u,p});
			if(i<n&&s[u+m-1]!='#') g[u+m-1].push_back({u,p});
		}
	}
	priority_queue<pr,vector<pr>,greater<pr>> pq;
	for(int i=1;i<=n*m;i++)
		if(s[i]=='.') pq.push({0,i});
		else d[i]=inf;
	while(pq.size()){
		int u=pq.top().second;
		if(pq.top().first!=d[u]){
			pq.pop();
			continue;
		}
		pq.pop();
		for(auto e:g[u]){
			int v=e.first,w=e.second;
			if(d[v]>d[u]+w) pq.push({d[v]=d[u]+w,v});
		}
	}
	ll ans=inf;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		int u=m*(i-1)+j;
		if(s[u]=='#'||d[u]==inf) continue;
		if(i<n&&s[u+m]!='#'&&d[u+m]<inf) ans=min(ans,d[u]+d[u+m]);
		if(j<m&&s[u+1]!='#'&&d[u+1]<inf) ans=min(ans,d[u]+d[u+1]);
	}
	printf("%lld\n",ans<inf?ans:-1);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}