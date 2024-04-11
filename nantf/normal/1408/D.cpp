#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2020,mod=998244353;
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
int n,m,a[maxn],b[maxn],c[maxn],d[maxn],pl,suf[maxn*maxn],ans=1e9;
PII p[maxn*maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read(),b[i]=read();
	FOR(i,1,m) c[i]=read(),d[i]=read();
	FOR(i,1,n) FOR(j,1,m){
		if(c[j]<a[i]) continue;
		if(d[j]<b[i]) continue; 
		p[++pl]=MP(c[j]-a[i]+1,d[j]-b[i]+1);
	}
	sort(p+1,p+pl+1);
//	FOR(i,1,pl) printf("(%d,%d)\n",p[i].first,p[i].second);
	ROF(i,pl,1) suf[i]=max(suf[i+1],p[i].second);
	FOR(i,1,pl) if(i==pl || p[i].first!=p[i+1].first) ans=min(ans,p[i].first+suf[i+1]);
	if(!pl) ans=0;
	ans=min(ans,p[pl].first);
	ans=min(ans,suf[1]);
	printf("%d\n",ans);
}