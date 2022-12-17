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
const int maxn=5e5+5;
int n,m,x[maxn],y[maxn];
char opt[maxn];
int cnt1,p1[maxn],cnt2,p2[maxn];
vector<int> g1[maxn*2],g2[maxn*2];
int pos1[maxn*2],size1[maxn*2],f1=0;
void dfs1(int u){
	pos1[u]=++f1;
	size1[u]=1;
	for(int v:g1[u]){
		dfs1(v);
		size1[u]+=size1[v];
	}
}
int pos2[maxn*2],size2[maxn*2],f2=0;
void dfs2(int u){
	pos2[u]=++f2;
	size2[u]=1;
	for(int v:g2[u]){
		dfs2(v);
		size2[u]+=size2[v];
	}
}
struct seg{
	int l,r,v;
	bool operator <(const seg b)const{
		return r<b.r;
	}
};
set<seg> s;
typedef set<seg>::iterator iter;
void split(int x){
	iter it=s.lower_bound({x,x,0});
	if(it==s.end()) return;
	seg u=*it;
	s.erase(u);
	if(u.l<x) s.insert({u.l,x-1,u.v});
	s.insert({x,u.r,u.v});
}
vector<int> q[maxn];
ll c[maxn*2];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,int k){
	while(x<=n*2){
		c[x]+=k;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
ll res[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	cnt1=cnt2=n;
	for(int i=1;i<=n;i++) p1[i]=p2[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%s",opt+i);
		if(opt[i]=='U'){
			x[i]=readint();
			y[i]=readint();
			cnt1++;
			g1[cnt1]={p1[x[i]],p1[y[i]]};
			p1[x[i]]=cnt1;
			p1[y[i]]=0;
		}
		else if(opt[i]=='M'){
			x[i]=readint();
			y[i]=readint();
			cnt2++;
			g2[cnt2]={p2[x[i]],p2[y[i]]};
			p2[x[i]]=cnt2;
			p2[y[i]]=0;
		}
		else x[i]=readint();
	}
	cnt1++;
	for(int i=1;i<=n;i++)
		if(p1[i]) g1[cnt1].push_back(p1[i]);
	cnt2++;
	for(int i=1;i<=n;i++)
		if(p2[i]) g2[cnt2].push_back(p2[i]);
	dfs1(cnt1);
	dfs2(cnt2);
	s={{1,cnt2,0}};
	cnt2=n;
	for(int i=1;i<=n;i++) p2[i]=i;
	for(int i=1;i<=m;i++)
		if(opt[i]=='M') p2[x[i]]=++cnt2;
		else if(opt[i]=='Z'){
			int l=pos2[p2[x[i]]],r=l+size2[p2[x[i]]]-1;
			split(l);
			split(r+1);
			iter it1,it2;
			it1=s.lower_bound({l,l,0});
			it2=s.upper_bound({r,r,0});
			s.erase(it1,it2);
			s.insert({l,r,i});
		}
		else if(opt[i]=='Q'){
			int t=s.lower_bound({0,pos2[x[i]],0})->v;
			q[t].push_back(i);
		}
	cnt1=n;
	for(int i=1;i<=n;i++) p1[i]=i;
	for(int i=1;i<=m;i++){
		if(opt[i]=='U') p1[x[i]]=++cnt1;
		else if(opt[i]=='A'){
			int l=pos1[p1[x[i]]],r=l+size1[p1[x[i]]]-1;
			modify(l,(size1[p1[x[i]]]+1)/2);
			modify(r+1,-(size1[p1[x[i]]]+1)/2);
		}
		else if(opt[i]=='Q')
			printf("%lld\n",query(pos1[x[i]])-res[i]);
		for(int u:q[i]) res[u]=query(pos1[x[u]]);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}