#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
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
inline int qmo(int x){return x+(x>>31)*mod;}
int n,a[maxn];
ll k;
void solve(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read();
	if(n==1) puts("0");
	else{
		k=k%2?1:2;
		while(k--){
			int mx=-1e9;
			FOR(i,1,n) mx=max(mx,a[i]);
			FOR(i,1,n) a[i]=mx-a[i];
		}
		FOR(i,1,n) printf("%d ",a[i]);
		puts("");
	}
}
int main(){
	int T=read();
	while(T--) solve();
}