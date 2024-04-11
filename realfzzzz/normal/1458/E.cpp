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
int n,m,x[maxn],y[maxn],a[maxn],b[maxn];
set<pair<int,int>> s;
int ord1[maxn],ord2[maxn];
struct bit{
	multiset<pair<int,int>> c[maxn];
	void insert(int x,int k){
		pair<int,int> p={k,x};
		while(x<=n){
			c[x].insert(p);
			x+=x&-x;
		}
	}
	void erase(int x,int k){
		pair<int,int> p={k,x};
		while(x<=n){
			c[x].erase(c[x].find(p));
			x+=x&-x;
		}
	}
	auto query(int x){
		pair<int,int> s={2e9,0};
		while(x){
			if(c[x].size()) s=min(s,*c[x].begin());
			x-=x&-x;
		}
		return s;
	}
}t1,t2;
bool ans[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
		y[i]=read();
		s.insert({x[i],y[i]});
		ord1[i]=y[i]-x[i];
	}
	sort(ord1+1,ord1+n+1);
	for(int i=1;i<=n;i++){
		int u=lower_bound(ord1+1,ord1+n+1,y[i]-x[i])-ord1;
		t1.insert(u,x[i]);
		t2.insert(n-u+1,y[i]);
	}
	for(int i=1;i<=m;i++){
		a[i]=read();
		b[i]=read();
		ord2[i]=i;
	}
	sort(ord2+1,ord2+m+1,[](int x,int y){
		return a[x]<a[y];
	});
	int x0=0,y0=0,c=1;
	auto chk=[&x0,&y0](int a,int b,bool f){
		return !s.count({a,b})&&(!f||b-a!=y0-x0);
	};
	while(1){
		pair<int,int> p1,p2;
		p1=t1.query(lower_bound(ord1+1,ord1+n+1,y0-x0)-ord1-1);
		p2=t2.query(n+ord1-upper_bound(ord1+1,ord1+n+1,y0-x0)+1);
		if(!p1.second&&!p2.second){
			while(c<=m){
				int u=ord2[c++];
				ans[u]=chk(a[u],b[u],1);
			}
			break;
		}
		else if(p1.first-x0<p2.first-y0){
			int x1=p1.first,y1=x1+ord1[p1.second];
			t1.erase(p1.second,x1);
			t2.erase(n-p1.second+1,y1);
			if(x1<x0) continue;
			while(c<=m&&a[ord2[c]]<=x1){
				int u=ord2[c++];
				ans[u]=chk(a[u],b[u],a[u]<x1);
			}
			y0=x1+y0-x0;
			x0=x1+1;
		}
		else{
			int y1=p2.first,x1=y1-ord1[n-p2.second+1];
			t1.erase(n-p2.second+1,x1);
			t2.erase(p2.second,y1);
			if(y1<y0) continue;
			while(c<=m&&a[ord2[c]]<y1-y0+x0){
				int u=ord2[c++];
				ans[u]=chk(a[u],b[u],1);
			}
			x0=y1-y0+x0;
			y0=y1+1;
		}
	}
	for(int i=1;i<=m;i++) printf(ans[i]?"WIN\n":"LOSE\n");
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}