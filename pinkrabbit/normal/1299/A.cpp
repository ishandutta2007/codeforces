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
int n,m,q,k;
int a[MN],b[MN],c[MN];
vector<int>G[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)b[i]=b[i-1]|a[i];
	dF(i,n,1)c[i]=c[i+1]|a[i];
	int ans=-1;
	F(i,1,n)if(((((a[i]|b[i-1])-b[i-1])|c[i+1])-c[i+1])>ans)k=i,ans=((((a[i]|b[i-1])-b[i-1])|c[i+1])-c[i+1]);
	printf("%d ",a[k]);
	F(i,1,n)if(i!=k)printf("%d ",a[i]);
	return 0;
}