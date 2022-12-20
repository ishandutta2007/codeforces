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
ll s[maxn];
vector<int> q[maxn];
int fa[maxn];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void op(int,int);
void upd(int x){
	fa[x]=x+1;
	for(int i:q[x]) if(fa[i]!=i) op(x,i);
}
void op(int l,int r){
	if(l>r) swap(l,r);
	int u=find(l);
	while(u<=r){
		upd(u);
		u=find(u+1);
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) s[i]=read();
		for(int i=1;i<=n;i++) s[i]-=read();
		for(int i=1;i<=n;i++) s[i]+=s[i-1];
		for(int i=0;i<=n;i++) q[i].clear();
		for(int i=1;i<=m;i++){
			int l,r;
			l=read()-1;
			r=read();
			q[r].push_back(l);
			q[l].push_back(r);
		}
		for(int i=0;i<=n+1;i++) fa[i]=i;
		for(int i=0;i<=n;i++) if(!s[i]) upd(i);
		printf(find(0)==n+1?"YES\n":"NO\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}