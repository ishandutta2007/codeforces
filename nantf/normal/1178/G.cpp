#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=400040,bl=1111,sz=444;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct line{
	ll k,b;
	int id;
	bool operator<(const line &l)const{return k<l.k;}
}vec[bl][sz],hull[bl][sz];
int n,q,el,head[maxn],to[maxn],nxt[maxn],in[maxn],out[maxn],dfs_cnt;
ll apre[maxn],bpre[maxn],a[maxn],b[maxn];
int sq,lft[bl],rig[bl],bel[maxn],at[bl],vl[bl],hl[bl];
ll tag[bl];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline double interx(line l1,line l2){
	return 1.0*(l1.b-l2.b)/(l2.k-l1.k);
}
void dfs(int u,int f){
	apre[u]+=apre[f];bpre[u]+=bpre[f];
	in[u]=++dfs_cnt;
	a[dfs_cnt]=apre[u];b[dfs_cnt]=bpre[u];
	for(int i=head[u];i;i=nxt[i]) dfs(to[i],u);
	out[u]=dfs_cnt;
}
void move(int id){
	while(at[id]<hl[id] && interx(hull[id][at[id]],hull[id][at[id]+1])<=tag[id]) at[id]++;
}
void build(int id){
	hl[id]=0;
	FOR(i,1,vl[id]){
		if(a[vec[id][i].id]>=0 && vec[id][i].k<0) continue;
		int tmp;
		bool flag=false;
		while((tmp=hl[id]) && hull[id][tmp].k==vec[id][i].k){
			if(hull[id][tmp].b<vec[id][i].b) hl[id]--;
			else{flag=true;break;}
		}
		if(flag) continue;
		while((tmp=hl[id])>1 && interx(hull[id][tmp-1],vec[id][i])<=interx(hull[id][tmp-1],hull[id][tmp])) hl[id]--;
		hull[id][++hl[id]]=vec[id][i];
	}
	at[id]=1;
}
void pushdown(int id){
	FOR(i,1,vl[id]){
		ll k=vec[id][i].k,b=vec[id][i].b;
		vec[id][i]=(line){k,b+k*tag[id],vec[id][i].id};
	}
	FOR(i,lft[id],rig[id]) a[i]+=tag[id];
	tag[id]=0;at[id]=1;
}
void init(){
	sq=max(1.0,sqrt(n/6));
	FOR(i,1,n){
		bel[i]=i/sq;
		if(bel[i]!=bel[i-1]){
			lft[bel[i]]=i;
			if(i!=1) rig[bel[i-1]]=i-1;
		}
	}
	rig[bel[n]]=n;
	FOR(i,1,n) b[i]=abs(b[i]);
	FOR(i,1,n){
		vec[bel[i]][++vl[bel[i]]]=(line){b[i],1ll*a[i]*b[i],i};
		vec[bel[i]][++vl[bel[i]]]=(line){-b[i],-1ll*a[i]*b[i],i};
	}
	FOR(i,bel[1],bel[n]){
		sort(vec[i]+1,vec[i]+vl[i]+1);
		build(i);
	}
}
void update_debris(int id,int l,int r,int v){
	pushdown(id);
	FOR(i,1,vl[id]){
		int x=vec[id][i].id;
		if(x>=l && x<=r) vec[id][i].b+=vec[id][i].k*v;
	}
	FOR(i,l,r) a[i]+=v;
	build(id);
}
void update(int l,int r,int v){
	if(bel[l]==bel[r]) return update_debris(bel[l],l,r,v);
	update_debris(bel[l],l,rig[bel[l]],v);
	update_debris(bel[r],lft[bel[r]],r,v);
	FOR(i,bel[l]+1,bel[r]-1) tag[i]+=v;
}
ll query_debris(int id,int l,int r){
	ll ans=0;
	FOR(i,l,r) ans=max(ans,abs(a[i]+tag[id])*b[i]);
	return ans;
}
ll query(int l,int r){
	if(bel[l]==bel[r]) return query_debris(bel[l],l,r);
	ll ans=max(query_debris(bel[l],l,rig[bel[l]]),query_debris(bel[r],lft[bel[r]],r));
	FOR(i,bel[l]+1,bel[r]-1){
		move(i);
		ll k=hull[i][at[i]].k,b=hull[i][at[i]].b,x=tag[i];
		ans=max(ans,k*x+b);
	}
	return ans;
}
int main(){
	n=read();q=read();
	FOR(i,2,n) add(read(),i);
	FOR(i,1,n) apre[i]=read();
	FOR(i,1,n) bpre[i]=read();
	dfs(1,0);
	init();
	while(q--){
		int op=read(),x=read();
		if(op==1) update(in[x],out[x],read());
		else printf("%lld\n",query(in[x],out[x]));
	}
}