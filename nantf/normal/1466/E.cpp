#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=1000000007;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,sum[maxn];
ll a[maxn];
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,0,59) sum[i]=0;
	FOR(i,1,n) FOR(j,0,59) if((a[i]>>j)&1) sum[j]=(sum[j]+(1ll<<j))%mod;
	int ans=0;
	FOR(i,1,n){
		int s1=0,s2=0;
		FOR(j,0,59) if((a[i]>>j)&1){
			s1=(s1+sum[j])%mod;
			s2=(s2+(1ll<<j)%mod*n)%mod;
		}
		else{
			s2=(s2+sum[j])%mod;
		}
		ans=(ans+1ll*s1*s2)%mod;
	}
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--) solve(); 
}