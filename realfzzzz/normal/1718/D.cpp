//
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
int n,m,p[maxn],a[maxn],st[maxn],tp,ch[maxn][2];
struct evt{
	int x,id,tp;
	bool operator <(evt b){
		return x<b.x;
	}
};
vector<evt> q;
const int inf=2e9;
int mn[maxn],mx[maxn];
bool flag;
void dfs(int u){
	mx[u]=a[u];
	for(int v:ch[u]) if(v){
		mn[v]=a[v]?a[v]:mn[u];
		dfs(v);
		mx[u]=max(mx[u],mx[v]);
	}
	if(a[u]) flag&=mx[u]==a[u];
	else{
		q.push_back({mx[u],u,1});
		q.push_back({mn[u],u,-1});
	}
}
bool vis[maxn];
struct cmp1{
	bool operator ()(int a,int b){
		if(mn[a]!=mn[b]) return mn[a]<mn[b];
		return a<b;
	}
};
struct cmp2{
	bool operator ()(int a,int b){
		if(mx[a]!=mx[b]) return mx[a]>mx[b];
		return a<b;
	}
};
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) p[i]=read();
		for(int i=1;i<=n;i++) a[i]=read();
		tp=0;
		for(int i=1;i<=n;i++){
			ch[i][0]=ch[i][1]=0;
			while(tp&&p[i]>p[st[tp]]) ch[i][0]=st[tp--];
			if(tp) ch[st[tp]][1]=i;
			st[++tp]=i;
		}
		int k=0;
		for(int i=1;i<=n;i++) k+=!a[i];
		q.clear();
		for(int i=1;i<k;i++) q.push_back({(int)read(),0,0});
		flag=1;
		mn[st[1]]=a[st[1]]?a[st[1]]:inf;
		dfs(st[1]);
		sort(q.begin(),q.end());
		set<int,cmp1> s1;
		int l=inf,r=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(evt x:q)
			if(x.tp==0){
				if(!s1.size()) continue;
				vis[*s1.begin()]=1;
				s1.erase(s1.begin());
			}
			else if(x.tp>0) s1.insert(x.id);
			else if(!vis[x.id]){
				if(r>0) flag=0;
				else{
					s1.erase(x.id);
					r=x.x;
				}
			}
		reverse(q.begin(),q.end());
		set<int,cmp2> s2;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(evt x:q)
			if(x.tp==0){
				if(!s2.size()) continue;
				vis[*s2.begin()]=1;
				s2.erase(s2.begin());
			}
			else if(x.tp<0) s2.insert(x.id);
			else if(!vis[x.id]){
				if(l<inf) flag=0;
				else{
					s2.erase(x.id);
					l=x.x;
				}
			}
		if(!flag) r=0;
		while(m--){
			int d=read();
			printf(l<=d&&d<=r?"YES\n":"NO\n");
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}