#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=4444444,mod=998244353,A1=(1<<20)-1;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,q,rt,ch[maxn][2],s1[maxn],s2[maxn],sz[maxn],add[maxn],stk[maxn],tp;
inline void pushup(int x){
	s1[x]=A1;s2[x]=sz[x]=0;
	FOR(i,0,1) if(ch[x][i]) s1[x]&=s1[ch[x][i]],s2[x]|=s2[ch[x][i]],sz[x]+=sz[ch[x][i]];
}
inline void setadd(int x,int v,int dep){
	if((v>>dep)&1) swap(ch[x][0],ch[x][1]);
	add[x]^=v;
	v&=s1[x]^s2[x]^A1;
	s1[x]^=v;
	s2[x]^=v;
}
inline void pushdown(int x,int dep){
	if(add[x]){
		FOR(i,0,1) if(ch[x][i]) setadd(ch[x][i],add[x],dep-1);
		add[x]=0;
	}
}
inline int newnode(){
	int now=stk[tp--];
	ch[now][0]=ch[now][1]=sz[now]=s1[now]=s2[now]=add[now]=0;
	return now;
}
void init(){
	ROF(i,maxn-100,1) stk[++tp]=i;
}
void merge(int &x,int &y,int dep){
	if(!x || !y) return x|=y,y=0,void();
	if(dep==-1) return sz[x]|=sz[y],s1[x]|=s1[y],s2[x]|=s2[y],stk[++tp]=y,y=0,void();
	pushdown(x,dep);pushdown(y,dep);
	FOR(i,0,1) merge(ch[x][i],ch[y][i],dep-1);
	pushup(x);
	stk[++tp]=y;y=0;
}
void insert(int &x,int v,int dep=19){
	if(!x) x=newnode();
	if(dep==-1) return s1[x]=s2[x]=v,sz[x]=1,void();
	pushdown(x,dep);
	insert(ch[x][(v>>dep)&1],v,dep-1);
	pushup(x);
}
struct node{
	int x,w,d;
}tmp[maxn];
int tl;
void split(int &x,int l,int r,int w=0,int dep=19){
	if(!x) return;
	if(r<w || w+((1<<(dep+1))-1)<l) return;
	if(l<=w && w+((1<<(dep+1))-1)<=r){
		tmp[++tl]=(node){x,w,dep};
		x=0;
		return;
	}
	pushdown(x,dep);
	split(ch[x][0],l,r,w,dep-1);
	split(ch[x][1],l,r,w|(1<<dep),dep-1);
	pushup(x);
}
void insert2(int &x,node y,int v,int dep=19){
	if(!x) x=newnode();
	if(dep==y.d){
		merge(x,y.x,dep);
		return;
	}	
	pushdown(x,dep);
	insert2(ch[x][(v>>dep)&1],y,v,dep-1);
	pushup(x);
}
void work1(int x,int v,int dep){
	if(!x) return;
	if(dep==-1 || !((s1[x]^s2[x])&(v^A1))) return setadd(x,s2[x]&(v^A1),dep);
	pushdown(x,dep);
	FOR(i,0,1) work1(ch[x][i],v,dep-1);
	if(!((v>>dep)&1)) merge(ch[x][0],ch[x][1],dep-1);
	pushup(x);
}
void work2(int x,int v,int dep){
	if(!x) return;
	if(dep==-1 || !((s1[x]^s2[x])&v)) return setadd(x,(s1[x]^A1)&v,dep);
	pushdown(x,dep);
	FOR(i,0,1) work2(ch[x][i],v,dep-1);
	if((v>>dep)&1) merge(ch[x][1],ch[x][0],dep-1);
	pushup(x);
}
void update1(int v){
	FOR(i,1,tl){
		work1(tmp[i].x,v,tmp[i].d);
		insert2(rt,tmp[i],v&tmp[i].w);
	}
}
void update2(int v){
	FOR(i,1,tl){
		work2(tmp[i].x,v,tmp[i].d);
		insert2(rt,tmp[i],v|tmp[i].w);
	}
}
void update3(int v){
	FOR(i,1,tl){
		setadd(tmp[i].x,v,tmp[i].d);
		insert2(rt,tmp[i],v^tmp[i].w);
	}
}
int query(int x,int l,int r,int w=0,int dep=19){
	if(!x) return 0;
	if(r<w || w+((1<<(dep+1))-1)<l) return 0;
	if(l<=w && w+((1<<(dep+1))-1)<=r) return sz[x];
	pushdown(x,dep);
	return query(ch[x][0],l,r,w,dep-1)+query(ch[x][1],l,r,w|(1<<dep),dep-1);
}
int main(){
	init();
	n=read();q=read();
	FOR(i,1,n) insert(rt,read());
	while(q--){
		int op=read(),l=read(),r=read(),x=op==4?0:read();
		if(op==4) printf("%d\n",query(rt,l,r));
		else{
			tl=0;
			split(rt,l,r);
			if(op==1) update1(x);
			if(op==2) update2(x);
			if(op==3) update3(x);
		}
	}
}