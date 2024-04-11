#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=888888,mod=998244353;
#define fst first
#define scd second
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
int n,a[maxn],b[maxn],a1[maxn],a2[maxn],b1[maxn],b2[maxn],at[maxn],bt[maxn],el=1,head[maxn],to[maxn],nxt[maxn],ans[maxn],al;
int sl,h,r,tr[maxn],seq[maxn],q[maxn],f1[maxn],f2[maxn];
PII w[maxn];
bool vis[maxn],in[maxn];
inline void add(int u,int v,PII ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
inline bool sgn(int x){return x>0;}
inline int getf1(int x){return x==f1[x]?x:f1[x]=getf1(f1[x]);}
inline int getf2(int x){return x==f2[x]?x:f2[x]=getf2(f2[x]);}
void work(){
	h=1;r=0;
	FOR(i,1,sl){
		int p=seq[i];
		if(h<=r && sgn(w[q[r]].fst)==sgn(w[p].fst)){
			int x=to[q[r]^1],y=to[q[r]],z=to[p];
			if(sgn(w[q[r]].fst)){
				tr[getf2(x)]=getf1(y);tr[getf2(y)]=getf1(z);
				f1[getf1(z)]=getf1(x);
				f2[getf2(x)]=getf2(z);
			}
			else{
				tr[getf2(y)]=getf1(x);tr[getf2(z)]=getf1(y);
				f1[getf1(x)]=getf1(z);
				f2[getf2(z)]=getf2(x);
			}
			r--;
		}
		else q[++r]=p;
	}
	while(r-h+1>2){
		if(sgn(w[q[h]].fst)==sgn(w[q[r]].fst)){
			int x=to[q[r]^1],y=to[q[r]],z=to[q[h]];
			if(sgn(w[q[r]].fst)){
				tr[getf2(x)]=getf1(y);tr[getf2(y)]=getf1(z);
				f1[getf1(z)]=getf1(x);
				f2[getf2(x)]=getf2(z);
			}
			else{
				tr[getf2(y)]=getf1(x);tr[getf2(z)]=getf1(y);
				f1[getf1(x)]=getf1(z);
				f2[getf2(z)]=getf2(x);
			}
			h++;r--;
		}
		else break;
	}
	if(r-h+1!=2 || sgn(w[q[h]].fst)==sgn(w[q[r]].fst)) puts("NO"),exit(0);
	int x=to[q[h]^1],y=to[q[h]];
	if(sgn(w[q[h]].fst)){
		tr[getf2(x)]=getf1(y);
	}
	else{
		tr[getf2(y)]=getf1(x);
	}
}
void dfs(int u,int f){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if((i^1)==f) continue;
		if(vis[v]){
			if(f){
				seq[++sl]=i;
				work();
				sl--;
				return;
			}
			continue;
		}
		seq[++sl]=i;
		dfs(v,i);
		sl--;
	}
}
void dfs(int u){
	ans[++al]=u;
	if(tr[u]) dfs(tr[u]);
}
int main(){
	n=read();
	FOR(i,1,2*n){
		a[i]=read();b[i]=read();
		(a[i]>0?a1[a[i]]:a2[-a[i]])=i;
		(b[i]>0?b1[b[i]]:b2[-b[i]])=i;
	}
	FOR(i,1,n){
		add(a1[i],a2[i],PII(i,0));
		add(a2[i],a1[i],PII(-i,0));
		add(b1[i],b2[i],PII(i,1));
		add(b2[i],b1[i],PII(-i,1));
	}
	FOR(i,1,2*n) f1[i]=f2[i]=i;
	FOR(i,1,2*n) if(!vis[i]) dfs(i,0);
	FOR(i,1,2*n) if(tr[i]) in[tr[i]]=true;
	FOR(i,1,2*n) if(!in[i]) dfs(i);
	puts("YES");
	FOR(i,1,2*n) printf("%d %d\n",a[ans[i]],b[ans[i]]);
}