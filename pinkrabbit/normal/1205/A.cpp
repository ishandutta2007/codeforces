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
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d",&n);
	if(~n&1)return puts("NO"),0;
	ll s=(ll)2*n*(2*n+1)/2;
	puts("YES");
	F(i,1,n)a[i]=i*2-1,a[n+i]=i*2;
	F(i,1,n)if(i&1)swap(a[i],a[n+i]);
	F(i,1,2*n)printf("%d ",a[i]);
	return 0;
}