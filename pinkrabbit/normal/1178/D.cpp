#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
inline bool ip(int n){for(int i=2;i*i<=n;++i)if(n%i==0)return 0;return 1;}
int main(){
	scanf("%d",&n);
	if(ip(n)){
		printf("%d\n",n);
		F(i,1,n)printf("%d %d\n",i,i%n+1);
		return 0;
	}
	m=n;
	while(!ip(m))++m;
	printf("%d\n",m),m-=n;
	F(i,1,n)printf("%d %d\n",i,i%n+1);
	F(i,1,m){
		if(i%4==1||i%4==2)printf("%d %d\n",i,(i+1)%n+1);
		else++m;
	}
	return 0;
}