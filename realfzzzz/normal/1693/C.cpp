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
const int maxn=2e5+5;
int n,m;
vector<int> g[maxn];
int d[maxn],cnt[maxn];
using pii=pair<int,int>;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();
		v=read();
		g[v].push_back(u);
		cnt[u]++;
	}
	for(int i=1;i<n;i++) d[i]=2e9;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,n});
	while(pq.size()){
		int u=pq.top().second;
		if(d[u]!=pq.top().first){
			pq.pop();
			continue;
		}
		pq.pop();
		for(int v:g[u]){
			cnt[v]--;
			if(d[v]>d[u]+cnt[v]+1)
				pq.push({d[v]=d[u]+cnt[v]+1,v});
		}
	}
	printf("%d\n",d[1]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}