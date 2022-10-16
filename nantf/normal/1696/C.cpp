#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
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
int n,m,k,al,bl;
PII a[maxn],b[maxn];
void clear(){
	FOR(i,1,al) a[i]=MP(0,0);
	FOR(i,1,bl) b[i]=MP(0,0);
	al=bl=0;
}
void solve(){
	n=read();m=read();
	FOR(i,1,n){
		int x=read(),c=1;
		while(x%m==0) x/=m,c*=m;
		if(x==a[al].fi) a[al].se+=c;
		else a[++al]=MP(x,c);
	}
	k=read();
	FOR(i,1,k){
		int x=read(),c=1;
		while(x%m==0) x/=m,c*=m;
		if(x==b[bl].fi) b[bl].se+=c;
		else b[++bl]=MP(x,c);
	}
	if(al!=bl) puts("No");
	else{
		bool flag=true;
		FOR(i,1,al) if(a[i]!=b[i]) flag=false;
		puts(flag?"Yes":"No");
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}