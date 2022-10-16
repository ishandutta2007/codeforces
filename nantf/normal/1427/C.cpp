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
int r,n,x[maxn],y[maxn],t[maxn],f[maxn];
int main(){
	r=read();n=read();
	FOR(i,1,n) t[i]=read(),x[i]=read(),y[i]=read();
	FOR(i,1,n) f[i]=-1e9;
	x[0]=y[0]=1;
	int mx=-1e9;
	FOR(i,1,n){
		FOR(j,max(0,i-2*r),i-1) if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]) f[i]=max(f[i],f[j]+1);
		if(i-2*r>=0) mx=max(mx,f[i-2*r]);
		f[i]=max(f[i],mx+1);
	}
	FOR(i,0,n) mx=max(mx,f[i]);
	printf("%d\n",mx);
}