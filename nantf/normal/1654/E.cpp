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
int n,a[maxn],ans=1,cnt[maxn*800];
bool vis[maxn*2];
/*
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
*/
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,-400,400){
		FOR(j,1,n) ans=max(ans,++cnt[a[j]-j*i+40000000]);
		FOR(j,1,n) --cnt[a[j]-j*i+40000000];
	}
	ROF(i,n-1,1){
		FOR(j,i+1,min(n,i+400)){
			if((a[j]-a[i])%(j-i)==0){
				int d=(a[j]-a[i])/(j-i);
				ans=max(ans,++cnt[d+100000]+1);
			}
		}
		FOR(j,i+1,min(n,i+400)){
			if((a[j]-a[i])%(j-i)==0){
				int d=(a[j]-a[i])/(j-i);
				--cnt[d+100000];
			}
		}
	}
	printf("%d\n",n-ans);
}