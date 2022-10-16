#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=33333,mod=998244353;
const ll INF=1e18;
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
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
int n,m,a[maxn],b[maxn],s[maxn];
ll ans=INF,f[maxn];
char str[maxn];
inline void chkmin(ll &x,ll y){x=min(x,y);}
void dfs(int dep,int cnt,bool lst){
	if(dep==n){
		if(cnt!=m || lst) return;
//		FOR(i,0,n-1) printf("%d ",b[i]);
//		puts("");
		FOR(i,0,n-1) s[1<<i]=b[i];
		FOR(i,1,(1<<n)-1) s[i]=s[i&-i]+s[i^(i&-i)];
		MEM(f,0x3f);
		FOR(i,0,n-1) f[1<<i]=0;
		FOR(i,0,(1<<n)-1) if(f[i]<INF && s[i]>=0 && s[i]<=15) FOR(j,0,n-1) if(!((i>>j)&1)){
			chkmin(f[i|(1<<j)],f[i]|(ll)s[i]<<(j*4));
		}
		chkmin(ans,f[(1<<n)-1]);
//		printf("ans=%lld\n",ans);
		return;
	}
	b[dep]=a[dep]-16+lst;
	dfs(dep+1,cnt+1,true);
	b[dep]=a[dep]+lst;
	dfs(dep+1,cnt,false);
}
int main(){
	scanf("%s",str);
	n=strlen(str);
	FOR(i,0,n-1) a[n-i-1]=str[i]<='9'?str[i]-'0':str[i]-'a'+10;
	FOR(i,0,n-1) m+=a[i];
	if(m%15) return puts("NO"),0;
	m/=15;
	dfs(0,0,false);
	if(ans==INF) puts("NO");
	else ROF(i,n-1,0){
		int x=(ans>>(i*4))&15;
		putchar(x<=9?x+'0':x-10+'a');
	}
}