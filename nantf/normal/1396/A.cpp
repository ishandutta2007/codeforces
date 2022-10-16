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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,a[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	if(n==1){
		puts("1 1");
		printf("%d\n",-a[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	printf("%d %d\n",1,n-1);
	FOR(i,1,n-1) printf("%lld ",1ll*(n-1)*a[i]);
	puts("");
	printf("%d %d\n",2,n);
	FOR(i,2,n-1) printf("0 ");
	printf("%lld\n",1ll*(n-1)*a[n]);
	printf("%d %d\n",1,n);
	FOR(i,1,n) printf("%lld ",-1ll*n*a[i]);
}