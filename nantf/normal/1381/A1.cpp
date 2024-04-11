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
int T,n,ans[maxn*2],al;
char a[maxn],b[maxn];
void work(int n){
	ans[++al]=n;
	FOR(i,1,n) a[i]^=1;
	FOR(i,1,n) if(i<n-i+1) swap(a[i],a[n-i+1]);
}
void solve(){
	n=read();
	scanf("%s%s",a+1,b+1);
	al=0;
	for(;n;n--){
		if(a[n]==b[n]) continue;
		if(n==1) work(1);
		else if(a[1]!=b[n]) work(n);
		else work(1),work(n);
	}
	printf("%d ",al);
	FOR(i,1,al) printf("%d ",ans[i]);
	puts("");
}
int main(){
	T=read();
	while(T--) solve();
}