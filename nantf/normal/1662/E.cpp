#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,p[maxn],q[maxn],b[maxn],pre[maxn],stk[maxn],tp;
inline void update(int p,int v){
	for(int i=p;i<=n;i+=i&-i) b[i]+=v;
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=b[i];
	return s;
}
void clear(){
	FOR(i,1,n) p[i]=q[i]=b[i]=pre[i]=stk[i]=0;
	tp=0;
}
void solve(){
	n=read();
	FOR(i,1,n) q[i]=read();
	FOR(i,1,n) if(q[i]==1){
		FOR(j,i,n) p[j-i+1]=q[j];
		FOR(j,1,i-1) p[n-i+1+j]=q[j];
		break;
	}
	FOR(i,1,n) q[p[i]]=i;
	FOR(i,1,n){
		while(tp && p[stk[tp]]>p[i]) tp--;
		pre[i]=stk[tp];
		stk[++tp]=i;
	}
	ll ans=0;
	FOR(i,1,n){
		if(i>=3){
			int tmp=0;
//			q[i-1] to pre[q[i]]
			if(q[i-1]<=pre[q[i]]) tmp=query(pre[q[i]])-query(q[i-1]);
			else tmp=query(n)-query(q[i-1])+query(pre[q[i]]);
			ans+=1ll*tmp*(n-i+1);
		}
		update(q[i],1);
	}
	printf("%lld\n",ans);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}