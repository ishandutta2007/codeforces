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
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		F(i,1,n)scanf("%d%d",a+i,b+i);
		a[0]=-3;
		ll A[3];
		F(j,0,2)A[j]=0;
		F(i,1,n){
			ll B[3];
			F(j,0,2){B[j]=0x3f3f3f3f3f3f3f3f;F(k,0,2)if(a[i-1]+k!=a[i]+j)B[j]=min(B[j],A[k]);B[j]+=j*b[i];}
			F(j,0,2)A[j]=B[j];
		}
		printf("%lld\n",min(A[0],min(A[1],A[2])));
	}
	return 0;
}