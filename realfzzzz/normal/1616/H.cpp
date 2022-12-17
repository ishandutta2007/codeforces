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
const int maxn=1.5e5+5;
int n,x,cnt=1,ch[maxn*40][2],sz[maxn*40];
void insert(int x){
	int u=1;
	sz[1]++;
	for(int i=30;i>=0;i--){
		bool k=x>>i&1;
		if(!ch[u][k]) ch[u][k]=++cnt;
		sz[u=ch[u][k]]++;
	}
}
const ll mod=998244353;
ll pw[maxn];
ll dfs(int u1,int u2,int d){
	if(!u1) return pw[sz[u2]];
	if(!u2) return pw[sz[u1]];
	if(u1==u2){
		if(d<0) return pw[sz[u1]];
		int lc=ch[u1][0],rc=ch[u1][1];
		if(x>>d&1) return dfs(lc,rc,d-1);
		else return (dfs(lc,lc,d-1)+dfs(rc,rc,d-1)-1+mod)%mod;
	}
	else{
		if(d<0) return pw[sz[u1]+sz[u2]];
		int lc1=ch[u1][0],rc1=ch[u1][1],lc2=ch[u2][0],rc2=ch[u2][1];
		if(x>>d&1) return dfs(lc1,rc2,d-1)*dfs(rc1,lc2,d-1)%mod;
		else{
			ll res=(dfs(lc1,lc2,d-1)+dfs(rc1,rc2,d-1)-1+mod)%mod;
			res=(res+(pw[sz[lc1]]-1+mod)*(pw[sz[rc1]]-1+mod)%mod)%mod;
			res=(res+(pw[sz[lc2]]-1+mod)*(pw[sz[rc2]]-1+mod)%mod)%mod;
			return res;
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	x=readint();
	for(int i=1;i<=n;i++) insert(readint());
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	printf("%lld\n",(dfs(1,1,30)-1+mod)%mod);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}