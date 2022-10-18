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
inline ll ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return read();
}
int n;
void solve(){
	n=read();
	ll x=ask(1,n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		ll y=ask(1,mid);
		if(x==y) r=mid;
		else l=mid+1;
	}
	ll y=ask(1,r-1);
	int b=x-y+1;
	x-=1ll*b*(b-1)/2;
	int a=sqrt(x*2);
	while(1ll*a*(a-1)/2<x) a++; 
	while(1ll*a*(a-1)/2>x) a--;
	printf("! %d %d %d\n",r-a-b+1,r-b+1,r);
	fflush(stdout);
}
int main(){
	int T=read();
	while(T--) solve();
}