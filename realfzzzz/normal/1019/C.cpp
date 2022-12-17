// LUOGU_RID: 93464297
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
const int maxn=1e6+5;
int n,m;
vector<int> g[maxn],g2[maxn];
int a[maxn];
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
		g[u].push_back(v);
		g2[v].push_back(u);
	}
	for(int i=1;i<=n;i++) if(!a[i]){
		a[i]=1;
		for(int v:g[i]) a[v]|=2;
	}
	vector<int> ans;
	for(int i=n;i>0;i--)
		if(a[i]&1){
			a[i]=1;
			for(int v:g2[i]) if(v>i) a[i]&=!a[v];
			if(a[i]) ans.push_back(i);
		}
		else a[i]=0;
	printf("%d\n",(int)ans.size());
	for(int i:ans) printf("%d ",i);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}