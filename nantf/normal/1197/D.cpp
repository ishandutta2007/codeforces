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
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,k,a[maxn];
ll s[maxn],v[maxn],val[10],ans;
int main(){
	n=read();m=read();k=read();
	FOR(i,1,n){
		a[i]=read();
		s[i]=s[i-1]+a[i];
		v[i]=s[i]-1ll*k*(i/m);
	}
	MEM(val,0x3f);
	val[0]=0;
	FOR(i,1,n){
		FOR(j,0,m-1) ans=max(ans,ll(v[i]-val[j]-1ll*k*((i%m-j+m-1)/m)));
		val[i%m]=min(val[i%m],v[i]);
	}
	cout<<ans<<endl;
}