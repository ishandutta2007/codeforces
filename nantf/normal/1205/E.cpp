#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=1000000007;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,k,ans,pw[maxn],pr[maxn],pl,mu[maxn],s[maxn];
bool vis[maxn];
vector<int> d[maxn];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int C2(int x){return 1ll*x*(x-1)/2%mod;}
int main(){
	read(n);read(k);
	if(k==1) return printf("%lld\n",1ll*(n-1)*(n-1)%mod),0;
	pw[0]=1;
	FOR(i,1,n) pw[i]=1ll*pw[i-1]*k%mod;
	mu[1]=1;
	FOR(i,2,n){
		if(!vis[i]) pr[++pl]=i,mu[i]=-1;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>n) break;
			vis[k]=true;
			if(i%pr[j]==0){mu[k]=0;break;}
			else mu[k]=-mu[i];
		}
	}
	FOR(i,1,n) mu[i]=(mod+mu[i])%mod;
	FOR(i,1,n-1) FOR(j,1,(n-1)/i){
		d[i*j].PB(i);
		ans=(ans+1ll*mu[j]*pw[i]%mod*C2((n+i-1)/(i*j)))%mod;
	}
	FOR(i,1,n-1){
		int upr=(2*n-2)/i;
		FOR(j,1,upr){
			if(i*j>=n) s[j]=1ll*((n-1)/i*2-j+1)*pw[i*j-n]%mod;
			else s[j]=0;
		}
		s[upr+1]=0;
		ROF(j,upr,1) s[j]=(s[j]+s[j+1])%mod;
		FOR(j,0,(int)d[i].size()-1) ans=(ans+1ll*s[(n+d[i][j]-1)/i+1]*mu[i/d[i][j]])%mod;
	}
	ans=1ll*ans*qpow(k,mod-1-n)%mod;
	printf("%d\n",ans);
}