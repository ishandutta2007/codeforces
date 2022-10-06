#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,q,v=100000;
int a[MN],b[MN],f[MN],g[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),++b[a[i]];
	int n2=0,n4=0,n6=0,n8=0;
	F(i,1,v){
		if(b[i]>=2)++n2;
		if(b[i]>=4)++n4;
		if(b[i]>=6)++n6;
		if(b[i]>=8)++n8;
	}
	scanf("%d",&q);
	while(q--){
		char s[3];int x;
		scanf("%s%d",s,&x);
		if(b[x]>=2)--n2;
		if(b[x]>=4)--n4;
		if(b[x]>=6)--n6;
		if(b[x]>=8)--n8;
		if(*s=='+'){
			++b[x];
		}else{
			--b[x];
		}
		if(b[x]>=2)++n2;
		if(b[x]>=4)++n4;
		if(b[x]>=6)++n6;
		if(b[x]>=8)++n8;
//		printf("%d,%d,%d,%d\n",n2,n4,n6,n8);
		if(n8)puts("YES");
		else if(n6&&n2>1)puts("YES");
		else if(n4>1)puts("YES");
		else if(n4&&n2>2)puts("YES");
		else puts("NO");
	}
	return 0;
}