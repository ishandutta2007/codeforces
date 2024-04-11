#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,maxm=1111111,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,m,q,a[maxn],pr[maxn],pl,mn[maxm],fa[maxn],id[maxn],at[maxm];
bool vis[maxm];
map<PII,bool> mp;
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x!=y) fa[x]=y;
}
inline bool check(int x,int y){
	x=getfa(x);y=getfa(y);
	return x==y;
}
int main(){
	read(n);read(q);
	FOR(i,1,n) read(a[i]),m=max(m,a[i]+1);
	FOR(i,2,m){
		if(!vis[i]) pr[++pl]=i,at[i]=pl+n,mn[i]=i;
		FOR(j,1,pl){
			if(i*pr[j]>m) break;
			vis[i*pr[j]]=true;
			mn[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	FOR(i,1,n+pl) fa[i]=i;
	FOR(i,1,n){
		int x=a[i];
		while(x!=1) unite(i,at[mn[x]]),x/=mn[x];
	}
	FOR(i,1,n+pl) id[i]=getfa(i);
	FOR(i,1,n){
		int x=a[i],tmp[111],tl=0;
		while(x!=1) tmp[++tl]=id[at[mn[x]]],x/=mn[x];
		x=a[i]+1;
		while(x!=1) tmp[++tl]=id[at[mn[x]]],x/=mn[x];
		sort(tmp+1,tmp+tl+1);tl=unique(tmp+1,tmp+tl+1)-tmp-1;
		FOR(j,1,tl) FOR(k,1,tl) mp[MP(tmp[j],tmp[k])]=true;
	}
	while(q--){
		int s,t;
		read(s);read(t);
		s=id[s];t=id[t];
		if(s==t) puts("0");
		else if(mp[MP(s,t)]) puts("1");
		else puts("2");
	}
}