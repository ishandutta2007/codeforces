#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> PII;
const int maxn=333333;
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
int n,m,al;
ll ans[maxn][3],c[maxn];
set<int> pos,neg;
inline void add(int u,int v,ll w){
	ans[++al][0]=u;
	ans[al][1]=v;
	ans[al][2]=w;
	c[u]-=w;c[v]+=w;
	if(!c[u]) pos.erase(u);
	if(!c[v]) neg.erase(v);
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		c[u]+=w;c[v]-=w;
	}
	FOR(i,1,n){
		if(c[i]>0) pos.insert(i);
		if(c[i]<0) neg.insert(i);
	}
	while(!pos.empty() && !neg.empty()){
		int u=*pos.begin(),v=*neg.begin();
		add(u,v,min(c[u],-c[v]));
	}
	assert(pos.empty() && neg.empty());
	printf("%d\n",al);
	FOR(i,1,al) printf("%lld %lld %lld\n",ans[i][0],ans[i][1],ans[i][2]);
}