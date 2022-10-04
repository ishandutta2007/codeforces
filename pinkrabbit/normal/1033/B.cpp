#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
#define LL long long
#define ld double
#define mod 1000000007

int n,m,q,k;
int a[1000005],b[1000005];
char str[1000005];
int fk[3005][3005];
int h[1000005],nxt[1000005],to[1000005],w[1000005],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
void ins(int x,int y,int z){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL b,a;
		scanf("%lld%lld",&b,&a);
		if(b>a+1) {puts("NO"); continue;}
		LL c=a+b;
		int ok=1;
		for(LL i=2;i*i<=c;++i) if(c%i==0) {puts("NO"); ok=0; break;}
		if(ok) puts("YES");
	}
	return 0;
}