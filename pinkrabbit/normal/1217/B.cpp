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
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		F(i,1,n)scanf("%d%d",a+i,b+i),f[i]=a[i]-b[i];
		int x=*max_element(a+1,a+n+1);
		if(m<=x){puts("1");continue;}
		m-=x;
		int y=*max_element(f+1,f+n+1);
		if(y<=0){puts("-1");continue;}
		printf("%d\n",(m-1)/y+2);
	}
	return 0;
}