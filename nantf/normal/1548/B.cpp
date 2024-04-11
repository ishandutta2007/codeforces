#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n;
ll a[maxn],b[maxn],s[maxn];
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int calc(int l,int r){
	if(l==r) return b[l]!=1;
	int mid=(l+r)>>1;
	int ans=max(calc(l,mid),calc(mid+1,r));
	s[mid]=b[mid];
	ROF(i,mid-1,l) s[i]=gcd(s[i+1],b[i]);
	s[mid+1]=b[mid+1];
	FOR(i,mid+2,r) s[i]=gcd(s[i-1],b[i]);
	int cur=mid+1;
	FOR(i,l,mid){
		while(cur<r && gcd(s[cur+1],s[i])!=1) cur++;
		if(gcd(s[cur],s[i])!=1) ans=max(ans,cur-i+1);
	}
//	FOR(i,mid+1,r) if(s[i]!=1) ans=max(ans,i-mid);
	return ans;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	if(n==1) return puts("1"),void();
	FOR(i,1,n-1) b[i]=abs(a[i]-a[i+1]);
	printf("%d\n",calc(1,n-1)+1);
}
int main(){
	int T=read();
	while(T--) solve();
}