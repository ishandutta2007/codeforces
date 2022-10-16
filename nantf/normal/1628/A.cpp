#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n,a[maxn],at[maxn],ans[maxn],m,cnt[maxn];
void clear(){
	FOR(i,0,n) at[i]=ans[i]=cnt[i]=0;
	m=0;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) at[a[i]]=i;
	int cur=0,lst=0;
	FOR(i,1,n){
		cnt[a[i]]++;
		while(cnt[cur]) cur++;
		if(at[cur]<=lst){
			ans[++m]=cur;
			cur=0;
			FOR(j,lst+1,i) cnt[a[j]]=0;
			lst=i;
		}
	}
	printf("%d\n",m);
	FOR(i,1,m) printf("%d ",ans[i]);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}