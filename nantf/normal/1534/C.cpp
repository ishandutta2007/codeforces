#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=1000000007;
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
int n,a[maxn],b[maxn],fa[maxn];
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) b[i]=read();
	FOR(i,1,n) fa[i]=i;
	int c=0;
	FOR(i,1,n){
		int x=getfa(a[i]),y=getfa(b[i]);
		if(x==y) c++;
		else fa[x]=y;
	}
	int p=1;
	FOR(i,1,c) p=2*p%mod;
	printf("%d\n",p);
}
int main(){
	int T=read();
	while(T--) solve(); 
}