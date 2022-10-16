#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n,m,k,el,head[maxn],to[maxn],nxt[maxn],deg[maxn],tdeg[maxn],tmp[maxn],tl;
bool vis[maxn];
struct hash_map{
	static const int SZ=100003,maxn=222222;
	int head[SZ],el,nxt[maxn];
	ll key[maxn];
	bool val[maxn];
	void clear(){
		FOR(i,1,el) head[key[i]%SZ]=0;
		FOR(i,1,el) key[i]=nxt[i]=val[i]=0;
		el=0;
	}
	bool& operator[](const ll &x){
		int id=x%SZ;
		for(int i=head[id];i;i=nxt[i]) if(key[i]==x) return val[i];
		key[++el]=x;
		nxt[el]=head[id];
		head[id]=el;
		return val[el];
	}
}mp;
set<PII> s;
void clear(){
	FOR(i,1,el) to[i]=nxt[i]=0;
	FOR(i,1,n) head[i]=deg[i]=0;
	el=0;
	s.clear();
	mp.clear();
}
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void work(int k){
	FOR(i,1,n) deg[i]=tdeg[i],vis[i]=false;//,printf("deg[%d]=%d\n",i,deg[i]);
	s.clear();
	FOR(i,1,n) s.insert(MP(deg[i],i));
	while(!s.empty() && s.begin()->first<k){
		int u=s.begin()->second;
//		printf("u=%d\n",u);
		s.erase(s.begin());
		vis[u]=true;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue;
			s.erase(MP(deg[v],v));
			deg[v]--;
			s.insert(MP(deg[v],v));
		}
	}
}
bool check(){
//	FOR(i,1,tl) printf("%d ",tmp[i]);
//	puts("");
/*	bitset<455> bt;
	FOR(i,1,tl) bt[tmp[i]]=1;
	FOR(i,1,tl){
		bitset<455> b=w[tmp[i]];
		b[tmp[i]]=1;
		if((bt&b)!=bt) return false;
	}*/
	FOR(i,1,tl) FOR(j,i+1,tl) if(!mp[1ll*tmp[i]*n+tmp[j]]) return false;
	puts("2");
	FOR(i,1,tl) printf("%d ",tmp[i]);
	puts("");
	return true;
}
void solve(){
	n=read();m=read();k=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
		deg[u]++;deg[v]++;
	}
	FOR(i,1,n) tdeg[i]=deg[i];
	work(k);
	if(!s.empty()){
		printf("1 %d\n",(int)s.size());
		for(set<PII>::iterator it=s.begin();it!=s.end();it++) printf("%d ",it->second);
		puts("");
	}
	else{
		if(k>450) puts("-1");
		else{
			FOR(u,1,n) for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				mp[1ll*n*u+v]=true;
			}
			FOR(i,1,n) deg[i]=tdeg[i],vis[i]=false;//,printf("deg[%d]=%d\n",i,deg[i]);
			s.clear();
			FOR(i,1,n) s.insert(MP(deg[i],i));
			while(!s.empty()){
				int u=s.begin()->second;
				s.erase(s.begin());
//				printf("u=%d,deg=%d\n",u,deg[u]);
				vis[u]=true;
				tl=0;
				for(int i=head[u];i;i=nxt[i]){
					int v=to[i];
					if(!vis[v]) tmp[++tl]=v;
				}
				tmp[++tl]=u;
//				printf("check %d\n",u);
				if(deg[u]==k-1 && check()) break;
				for(int i=head[u];i;i=nxt[i]){
					int v=to[i];
					if(vis[v]) continue;
//					printf("minus %d\n",v);
					s.erase(MP(deg[v],v));
					deg[v]--;
					s.insert(MP(deg[v],v));
				}
			}
			if(s.empty()) puts("-1");
		}
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}
/*
2
11 15 3
1 4
1 5
2 4
2 5
2 6
3 4
3 5
3 6
7 8
8 9
9 10
10 7
7 11
4 11
2 11

1
5 8 3
1 3
1 4
1 5
2 3
2 4
2 5
3 5
4 5

1
5 8 4
1 2
1 3
1 5
2 3
2 5
3 5
1 4
3 4
*/