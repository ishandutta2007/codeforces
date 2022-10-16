#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
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
int n,m,k,a[maxn],sl[2],cur;
PII s[2][11111111];
ll as0[maxn],as1[maxn];
void check(ll s0,ll s1){
	bool flag=false;
	FOR(i,0,n-1){
		if(((s0|s1)>>i)&1){
			if((s1>>i)&1) flag=true;
			else if(flag) puts("REJECTED"),exit(0);
		}
		else puts("REJECTED"),exit(0);
	}
}
int main(){
	n=read();m=read();
	if(n==1) return puts("ACCEPTED"),0;
	if(!m) return puts("REJECTED"),0;
	s[0][++sl[0]]=MP(0,0);
	while(m--){
		k=read();
		ll as=0;
		FOR(i,1,k) a[i]=read()-1,as|=1ll<<a[i];
		as0[0]=0,as1[0]=as;
		FOR(i,1,k){
			as0[i]=as0[i-1]|(1ll<<a[i]);
			as1[i]=as1[i-1]&(~(1ll<<a[i]));
		}
		FOR(_,1,sl[cur]){
			ll s0=s[cur][_].first,s1=s[cur][_].second;
			int c0=__builtin_popcountll(s0&as),c1=__builtin_popcountll(s1&as);
			FOR(i,c0,k-c1){
				s0&=~as;s1&=~as;
				s0|=as0[i];s1|=as1[i];
				if(!m) check(s0,s1);
				else s[cur^1][++sl[cur^1]]=MP(s0,s1);
			}
		}
		sl[cur]=0;
		cur^=1;
	}
	puts("ACCEPTED");
}