#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
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
int n,m,a[maxn],b[maxn];
ll pre[maxn];
void solve(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,m) b[i]=read();
	sort(a+1,a+n+1);
	FOR(i,1,n) pre[i]=pre[i-1]+b[a[i]];
	ll ans=1e18,sum=0;
	int mx=0;
	FOR(i,0,min(n,m)){
		if(i){
			mx=max(mx,lower_bound(a+1,a+n+1,i)-a-i+1);
			sum+=b[i];
		}
//		printf("i=%d,mx=%d\n",i,mx);
		if(mx<=n-i+1) ans=min(ans,sum+pre[n-i]);
	}
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--) solve(); 
}