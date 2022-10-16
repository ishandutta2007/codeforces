#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,w[maxn],deg[maxn],tmp[maxn],tl;
ll ans;
void clear(){
	FOR(i,1,n) deg[i]=0;
	tl=ans=0;
}
void solve(){
	n=read();
	FOR(i,1,n) w[i]=read();
	FOR(i,1,2*n-2) deg[read()]++;
	FOR(i,1,n) ans+=w[i];
	printf("%lld ",ans);
	FOR(i,1,n) FOR(j,1,deg[i]-1) tmp[++tl]=w[i];
	sort(tmp+1,tmp+tl+1,greater<int>());
	FOR(i,1,n-2){
		ans+=tmp[i];
		printf("%lld ",ans);
	}
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}