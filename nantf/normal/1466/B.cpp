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
int n,a[maxn];
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	ROF(i,n,1){
		if(i==n || a[i]+1!=a[i+1] && a[i]!=a[i+1]) a[i]++;
	}
	int ans=1;
	FOR(i,1,n-1) if(a[i]!=a[i+1]) ans++;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--) solve();
}