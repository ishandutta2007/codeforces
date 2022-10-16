#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353,INF=1e9;
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
int n,m,k,a[maxn],b[maxn],sz[maxn],p[maxn];
char s[33],t[33];
inline int tr(const char s[]){
	int ans=0;
	FOR(i,0,k-1) ans|=(s[i]-'0')<<p[i];
	return ans;
}
inline void chkmax(int &x,int y){x=max(x,y);}
inline void chkmin(int &x,int y){x=min(x,y);}
int main(){
	n=read();m=read();k=read();
	scanf("%s%s",s,t);
	FOR(i,0,(1<<k)-1) a[i]=-INF,b[i]=INF;
	FOR(i,0,k-1) p[i]=i;
	chkmax(a[tr(t)],0);chkmin(b[tr(s)],0);
	FOR(i,1,n){
		int x=read()-1,y=read()-1;
		swap(p[x],p[y]);
		chkmax(a[tr(t)],i);chkmin(b[tr(s)],i);
	}
	for(int i=1;i<(1<<k);i<<=1)
		for(int j=0;j<(1<<k);j+=i<<1)
			FOR(k,0,i-1){
				chkmax(a[j+k],a[i+j+k]);
				chkmin(b[j+k],b[i+j+k]);
			}
	int ans=0;
	FOR(i,0,(1<<k)-1){
		sz[i]=sz[i>>1]+(i&1);
		if(a[i]-b[i]>=m) chkmax(ans,sz[i]);
	}
	FOR(i,0,(1<<k)-1){
		if(a[i]-b[i]>=m && ans==sz[i]){
			ans=2*ans+k;
			FOR(j,0,k-1) if(s[j]=='1') ans--;
			FOR(j,0,k-1) if(t[j]=='1') ans--;
			printf("%d\n%d %d\n",ans,b[i]+1,a[i]);
			return 0;
		}
	}
}