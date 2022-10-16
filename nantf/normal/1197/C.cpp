#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,a[maxn],d[maxn];
ll ans;
int main(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n-1) d[i]=a[i]-a[i+1];
	sort(d+1,d+n);
	ans=a[n]-a[1];
	FOR(i,1,k-1) ans+=d[i];
	cout<<ans<<endl;
}