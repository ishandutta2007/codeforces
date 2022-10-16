#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020,mod=998244353;
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
int n,ans;
ll a[maxn],b[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=1ll*read()*i*(n-i+1);
	FOR(i,1,n) b[i]=read();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	FOR(i,1,n) ans=(ans+a[i]%mod*b[n-i+1])%mod;
	printf("%d\n",ans);
}