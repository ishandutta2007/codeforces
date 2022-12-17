#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e5+5,maxk=50+5;
int n,m,k,q,a[maxn],b[maxn],e[maxn],c[maxn];
typedef pair<int,int> pii;
struct dsu{
	int fa[maxn],s[maxn];
	bool w[maxn];
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			s[i]=1;
		}
	}
	pair<int,bool> find(int u){
		if(fa[u]==u) return {u,0};
		auto x=find(fa[u]);
		x.second^=w[u];
		return x;
	}
	int merge(int u,int v){
		auto x=find(u),y=find(v);
		if(x.first==y.first) return -1;
		if(s[x.first]>s[y.first]) swap(x,y);
		fa[x.first]=y.first;
		s[y.first]+=s[x.first];
		w[x.first]=!(x.second^y.second);
		return x.first;
	}
}s[maxk];
int lst[maxn],suc[maxn],now[maxn];
vector<pii> q2[maxn*4];
void modify(int o,int l,int r,int ql,int qr,int e,int c){
	if(ql<=l&&qr>=r){
		q2[o].push_back({e,c});
		return;
	}
	int mid=l+(r-l)/2;
	if(ql<=mid) modify(o*2,l,mid,ql,qr,e,c);
	if(qr>mid) modify(o*2+1,mid+1,r,ql,qr,e,c);
}
void solve(int o,int l,int r){
	vector<pii> vec;
	for(pii x:q2[o]){
		int e=x.first,c=x.second;
		vec.push_back({c,s[c].merge(a[e],b[e])});
	}
	if(l==r){
		int u=a[e[r]],v=b[e[r]];
		auto x=s[c[r]].find(u),y=s[c[r]].find(v);
		if(x==y){
			printf("NO\n");
			if(r<suc[r]-1&&now[e[r]])
				modify(1,1,q,r+1,suc[r]-1,e[r],now[e[r]]);
		}
		else{
			printf("YES\n");
			now[e[r]]=c[r];
			if(r<suc[r]-1)
				modify(1,1,q,r+1,suc[r]-1,e[r],now[e[r]]=c[r]);
		}
	}
	else{
		int mid=l+(r-l)/2;
		solve(o*2,l,mid);
		solve(o*2+1,mid+1,r);
	}
	reverse(vec.begin(),vec.end());
	for(pii x:vec){
		int c=x.first,u=x.second;
		if(u<0) continue;
		s[c].s[s[c].fa[u]]-=s[c].s[u];
		s[c].fa[u]=u;
		s[c].w[u]=0;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	k=readint();
	q=readint();
	for(int i=1;i<=m;i++){
		a[i]=readint();
		b[i]=readint();
	}
	for(int i=1;i<=q;i++){
		e[i]=readint();
		c[i]=readint();
	}
	for(int i=1;i<=m;i++) lst[i]=q+1;
	for(int i=q;i>0;i--){
		suc[i]=lst[e[i]];
		lst[e[i]]=i;
	}
	for(int i=1;i<=k;i++) s[i].init();
	solve(1,1,q);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}