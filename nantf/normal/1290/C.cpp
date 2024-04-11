#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
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
int n,k,a[maxn][2],l[maxn],ans,fa[maxn*2],sum[maxn*2],tag[maxn*2];
char s[maxn];
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline int rev(int x){
	return x<=k?x+k:x-k;
}
inline void work(int x,int w){
	if(!tag[x] && !tag[rev(x)]) ans+=w*min(sum[x],sum[rev(x)]);
	else if(tag[x]) ans+=w*sum[x];
	else ans+=w*sum[rev(x)];
} 
void same(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return;
	work(x,-1);
	work(y,-1);
	fa[x]=y;
	fa[rev(x)]=rev(y);
	sum[y]+=sum[x];
	sum[rev(y)]+=sum[rev(x)];
	tag[y]|=tag[x];
	tag[rev(y)]|=tag[rev(x)];
	work(y,1);
}
void differ(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==rev(y)) return;
	work(x,-1);
	work(y,-1);
	fa[x]=rev(y);
	fa[rev(x)]=y;
	sum[y]+=sum[rev(x)];
	sum[rev(y)]+=sum[x];
	tag[y]|=tag[rev(x)];
	tag[rev(y)]|=tag[x];
	work(y,1);
}
int main(){
	n=read();k=read();
	scanf("%s",s+1); 
	FOR(i,1,k){
		int c=read();
		while(c--){
			int x=read();
			a[x][l[x]++]=i;
		}
	}
	FOR(i,1,2*k) fa[i]=i,sum[i]=i>k,tag[i]=0;
	FOR(i,1,n){
		if(l[i]==1){
			int y=getfa(a[i][0]);
			work(y,-1);
			if(s[i]=='0') tag[rev(y)]=1;
			else tag[y]=1;
			work(y,1);
		}
		else if(l[i]==2){
			if(s[i]=='0') differ(a[i][0],a[i][1]);
			else same(a[i][0],a[i][1]);
		}
		printf("%d\n",ans);
	}
}
// must be easier than B