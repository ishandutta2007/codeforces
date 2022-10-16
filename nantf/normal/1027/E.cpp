#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555,mod=998244353;
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
int n,k,f[maxn],s[maxn],cnt[maxn],ans;
int main(){
	n=read();k=read()-1;
	FOR(i,1,n){
		f[0]=s[0]=1;
		FOR(j,1,n) f[j]=s[j]=0;
		FOR(j,1,n){
			f[j]=(s[j-1]-s[j-min(i,j)-1]+mod)%mod;
			s[j]=(s[j-1]+f[j])%mod;
		}
		cnt[i]=2*f[n]%mod;
	}
	ROF(i,n,1) cnt[i]=(cnt[i]-cnt[i-1]+mod)%mod;
	FOR(i,1,n){
		int lim=k/i;
		if(!lim) continue;
		f[0]=s[0]=1;
		FOR(j,1,n) f[j]=s[j]=0;
		FOR(j,1,n){
			f[j]=(s[j-1]-s[j-min(lim,j)-1]+mod)%mod;
			s[j]=(s[j-1]+f[j])%mod;
		}
		ans=(ans+1ll*cnt[i]*f[n])%mod;
	}
	printf("%d\n",ans);
}