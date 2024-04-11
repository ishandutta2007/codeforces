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
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
char s[MN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
	scanf("%d%s",&n,s+1);
	int x=0,y=0;
	F(i,1,n)if(s[i]=='1')x=i;
	dF(i,n,1)if(s[i]=='1')y=i;
	if(!x)printf("%d\n",n);
	else printf("%d\n",2*std::max(x,n-y+1));
	}
	return 0;
}