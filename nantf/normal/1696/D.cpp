#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=255555,mod=998244353;
#define fi first
#define se second
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],mn[20][maxn],mx[20][maxn],lt[maxn];
void clear(){
	FOR(i,0,lt[n]) FOR(j,1,n-(1<<i)+1) mn[i][j]=mx[i][j]=0;
	FOR(i,1,n) lt[i]=a[i]=0;
}
inline int qmn(int l,int r){
	int k=lt[r-l+1];
	int x=mn[k][l],y=mn[k][r-(1<<k)+1];
	return a[x]<a[y]?x:y;
}
inline int qmx(int l,int r){
	int k=lt[r-l+1];
	int x=mx[k][l],y=mx[k][r-(1<<k)+1];
	return a[x]>a[y]?x:y;
}
int calc(int l,int r){
	if(l==r) return 0;
	int p=qmn(l,r),q=qmx(l,r);
	if(p!=l && p!=r) return calc(l,p)+calc(p,r);
	if(q!=l && q!=r) return calc(l,q)+calc(q,r);
	return 1; 
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,2,n) lt[i]=lt[i>>1]+1;
	FOR(i,1,n) mn[0][i]=mx[0][i]=i;
	FOR(i,1,lt[n]) FOR(j,1,n-(1<<i)+1){
		int x=mn[i-1][j],y=mn[i-1][j+(1<<(i-1))];
		mn[i][j]=a[x]<a[y]?x:y;
		x=mx[i-1][j],y=mx[i-1][j+(1<<(i-1))];
		mx[i][j]=a[x]>a[y]?x:y;
	}
	printf("%d\n",calc(1,n));
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}