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
int nn,n,cnt[111];
bool f[100010];
ll ans;
int main(){
	nn=read();
	n=min(nn,20);
	f[0]=1;
	FOR(i,1,n) ROF(j,50*n,1) f[j]|=f[j-4]|f[j-9]|f[j-49];
	FOR(i,0,50*n) if(f[i]) ans++;
	if(nn<=20) cout<<ans<<endl;
	else cout<<ans+49ll*(nn-20)<<endl;
}