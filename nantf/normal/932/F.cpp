#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
struct line{
	int k;
	ll b;
	bool operator<(const line &l)const{
		if(k!=l.k) return k>l.k;
		return b<l.b;
	}
};
struct point{
	double x;
	int k;
	ll b;
	bool operator<(const point &p)const{return x<p.x;} 
};
int n,el,head[maxn],to[maxn*2],nxt[maxn*2],A[maxn],B[maxn];
ll f[maxn];
set<line> inter[maxn];
set<point> hull[maxn];
inline void add(int u,int v){to[++el]=v;nxt[el]=head[u];head[u]=el;}
double interx(line l1,line l2){
	return l1.k==l2.k?1e18:1.0*(l2.b-l1.b)/(l1.k-l2.k);
}
void remove(int id,set<line>::iterator it){
	set<line>::iterator it1=it,it2=it;it2++;
	if(it1!=inter[id].begin()){
		it1--;
		hull[id].erase((point){interx(*it,*it1),it1->k,it1->b});
		it1++;
	}
	if(it2!=inter[id].end()) hull[id].erase((point){interx(*it,*it2),it->k,it->b});
	if(it1!=inter[id].begin() && it2!=inter[id].end()){
		it1--;
		hull[id].insert((point){interx(*it1,*it2),it1->k,it1->b});
	}
	inter[id].erase(it);
}
void insert(int id,line l){
	set<line>::iterator it=inter[id].insert(l).first;
	set<line>::iterator it1=it,it2=it;it2++;
	if(it1!=inter[id].begin()){
		it1--;
		if(it1->k==it->k) return void(inter[id].erase(*it));
		it1++;
	}
	if(it1!=inter[id].begin() && it2!=inter[id].end()){
		it1--;
		if(interx(*it,*it1)>=interx(*it,*it2)) return void(inter[id].erase(*it));
		it1++;
	}
	if(it1!=inter[id].begin()){
		it1--;
		hull[id].insert((point){interx(*it,*it1),it1->k,it1->b});
		it1++;
	}
	if(it2!=inter[id].end()) hull[id].insert((point){interx(*it,*it2),it->k,it->b});
	if(it1!=inter[id].begin() && it2!=inter[id].end()){
		it1--;
		hull[id].erase((point){interx(*it1,*it2),it1->k,it1->b});
		it1++;
	}
	it=it1=inter[id].find(l);
	while(it1!=inter[id].begin()){
		it1--;
		if(it1==inter[id].begin()) break;
		it2=it1;it2--;
		if(interx(*it2,*it)<=interx(*it2,*it1)) remove(id,it1);
		else break;
		it=it1=inter[id].find(l);
	}
	it=it1=inter[id].find(l);it1++;
	while(it1!=inter[id].end()){
		it2=it1;it2++;
		if(it2!=inter[id].end() && interx(*it2,*it)>=interx(*it2,*it1) || it1->k==it->k) remove(id,it1);
		else break;
		it=it1=inter[id].find(l);it1++;
	}
}
void dfs(int u,int F){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		if(inter[u].size()<inter[v].size()) inter[u].swap(inter[v]),hull[u].swap(hull[v]);
		for(set<line>::iterator it=inter[v].begin();it!=inter[v].end();it++) insert(u,*it);
		inter[v].clear();hull[v].clear();
	}
	if(!inter[u].empty()){
		set<point>::iterator it=hull[u].lower_bound((point){A[u],0,0});
		int k;
		ll b;
		if(it==hull[u].end()){
			set<line>::iterator it=inter[u].end();it--;
			k=it->k;b=it->b;
		}
		else k=it->k,b=it->b;
		f[u]=1ll*k*A[u]+b;
	}
	insert(u,(line){B[u],f[u]});
}
int main(){
	n=read();
	FOR(i,1,n) A[i]=read();
	FOR(i,1,n) B[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	FOR(i,1,n) printf("%lld ",f[i]);
}