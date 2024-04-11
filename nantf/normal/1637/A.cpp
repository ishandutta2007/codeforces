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
int n,a[maxn],pre[maxn],suf[maxn];
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	pre[1]=a[1];
	FOR(i,2,n) pre[i]=max(a[i],pre[i-1]);
	suf[n]=a[n];
	ROF(i,n-1,1) suf[i]=min(a[i],suf[i+1]);
	FOR(i,1,n-1) if(pre[i]>suf[i]) return puts("YES"),void();
	puts("NO");
}
int main(){
	int T=read();
	while(T--) solve();
}