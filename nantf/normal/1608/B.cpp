#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
int n,a,b,aa,bb,ans[maxn],tp[maxn];
void solve(){
	n=read(),aa=a=read(),bb=b=read();
	if(abs(a-b)>1) return puts("-1"),void(); 
	bool flag=false;
	if(a<b) flag=true,swap(a,b);
	FOR(i,1,n) tp[i]=0;
	FOR(i,2,n-1){
		if(i%2==1){
			if(b) b--,tp[i]=2;
		}
		else{
			if(a) a--,tp[i]=1;
		}
	}
	if(a || b) return puts("-1"),void();
	int l=0,r=n+1;
	FOR(i,1,n) if(tp[i]==1) ans[i]=--r; else if(tp[i]==2) ans[i]=++l;
	if(aa==bb){
		FOR(i,1,n) if(!tp[i]) ans[i]=++l;
	}
	else{
		FOR(i,1,n) if(!tp[i]) ans[i]=--r;
	}
	if(flag) FOR(i,1,n) ans[i]=n-ans[i]+1;
	FOR(i,1,n) printf("%d ",ans[i]);
	puts(""); 
}
int main(){
	int T=read();
	while(T--) solve();
}