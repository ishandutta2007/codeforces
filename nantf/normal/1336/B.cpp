#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int t,n,m,k,a[maxn],b[maxn],c[maxn];
ll ans;
inline ll calc(int x,int y,int z){
	return 1ll*(x-y)*(x-y)+1ll*(x-z)*(x-z)+1ll*(y-z)*(y-z);
}
void work(int n,int m,int k,int a[],int b[],int c[]){
	FOR(i,1,n){
		int b1=lower_bound(b+1,b+m+1,a[i])-b;
		int b2=b1-1;
		int c1=lower_bound(c+1,c+k+1,a[i])-c;
		int c2=c1-1;
		if(b1!=m+1 && c1!=k+1) ans=min(ans,calc(a[i],b[b1],c[c1]));
		if(b1!=m+1 && c2) ans=min(ans,calc(a[i],b[b1],c[c2]));
		if(b2 && c1!=k+1) ans=min(ans,calc(a[i],b[b2],c[c1]));
		if(b2 && c2) ans=min(ans,calc(a[i],b[b2],c[c2]));
	}
}
int main(){
	t=read();
	while(t--){
		n=read();m=read();k=read();
		FOR(i,1,n) a[i]=read();
		FOR(i,1,m) b[i]=read();
		FOR(i,1,k) c[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		sort(c+1,c+k+1);
		ans=9e18;
		work(n,m,k,a,b,c);
		work(m,n,k,b,a,c);
		work(k,n,m,c,a,b);
		printf("%lld\n",ans);
	}
}