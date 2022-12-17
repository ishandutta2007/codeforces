// LUOGU_RID: 96456490
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
const int maxn=1e5+5;
int n,m,q,v[maxn],w[maxn];
vector<int> g[maxn];
const ll inf=9e18;
ll d[maxn];
using pr=pair<ll,int>;
int d2[maxn];
vector<int> b[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=m;i++){
		g[read()].push_back(i);
		v[i]=read();
		w[i]=read();
	}
	priority_queue<pr,vector<pr>,greater<pr>> pq;
	pq.push({0,1});
	for(int i=2;i<=n;i++) d[i]=inf;
	while(pq.size()){
		int u=pq.top().second;
		if(d[u]!=pq.top().first){
			pq.pop();
			continue;
		}
		pq.pop();
		for(int e:g[u]) if(d[v[e]]>d[u]+w[e])
			pq.push({d[v[e]]=d[u]+w[e],v[e]});
	}
	while(q--){
		int opt=read();
		if(opt==1){
			int u=read();
			printf("%lld\n",d[u]<inf?d[u]:-1);
		}
		else{
			int c=read();
			while(c--) w[read()]++;
			b[0].push_back(1);
			for(int i=2;i<=n;i++) d2[i]=n;
			for(int i=0;i<n;i++) while(b[i].size()){
				int u=b[i].back();
				b[i].pop_back();
				if(d2[u]!=i) continue;
				for(int e:g[u]) if(d2[v[e]]>d2[u]+d[u]+w[e]-d[v[e]])
					b[d2[v[e]]=d2[u]+d[u]+w[e]-d[v[e]]].push_back(v[e]);
			}
			for(int i=1;i<=n;i++) if(d[i]<inf) d[i]+=d2[i];
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}