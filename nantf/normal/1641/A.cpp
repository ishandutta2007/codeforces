#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
#define PB push_back
#define MP make_pair
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
int n,x,a[maxn];
bool vis[maxn];
void clear(){
	FOR(i,1,n) vis[i]=false;
}
void solve(){
	n=read();x=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int cur=n;
	ROF(i,n,1) if(!vis[i]){
		while(cur && (vis[cur] || 1ll*a[cur]*x>a[i])) cur--;
		if(1ll*a[cur]*x==a[i]) vis[cur]=vis[i]=true;
	}
	int ans=0;
	FOR(i,1,n) if(!vis[i]) ans++;
	printf("%d\n",ans);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}