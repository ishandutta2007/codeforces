#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,q,in[maxn],out[maxn];
ll ans;
vector<int> e[maxn];
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		if(u>v) swap(u,v);
		e[u].push_back(v);
		ans-=1ll*in[u]*out[u]+1ll*in[v]*out[v];
		in[u]++;out[v]++;
		ans+=1ll*in[u]*out[u]+1ll*in[v]*out[v];
	}
	printf("%lld\n",ans);
	q=read();
	while(q--){
		int u=read();
		ans-=1ll*in[u]*out[u];
		FOR(i,0,(int)e[u].size()-1){
			int v=e[u][i];
			e[v].push_back(u);
			ans-=1ll*in[v]*out[v];
			in[u]--;out[v]--;
			out[u]++;in[v]++;
			ans+=1ll*in[v]*out[v];
		}
		e[u].clear();
		ans+=1ll*in[u]*out[u];
		printf("%lld\n",ans);
	}
}