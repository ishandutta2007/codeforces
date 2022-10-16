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
int n,m,a[maxn],b[maxn];
ll ans;
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read(),ans+=1ll*a[i]*m;
	sort(a+1,a+n+1);
	int cur=n,cnt=0;
	FOR(i,1,m){
		b[i]=read();
		if(a[n]>b[i]) return puts("-1"),0;
		if(a[n]==b[i]) continue;
		if(!cur) return puts("-1"),0;
		ans+=b[i]-a[cur];
		cnt++;
		if(cnt==m-1) cur--;
	}
	cout<<ans;
}