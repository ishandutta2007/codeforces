#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=1000000007;
#define MP make_pair
#define PB push_back
#define ls o<<1
#define rs o<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,x[maxn],y[maxn];
PII xx[maxn],yy[maxn];
ll ans;
int main(){
//	freopen("play2.in","r",stdin);
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read();
	FOR(i,1,n) xx[i]=MP(x[i],i),yy[i]=MP(y[i],i);
	sort(xx+1,xx+n+1);
	sort(yy+1,yy+n+1);
	if(n%2){
		int mid=(n+1)/2;
		FOR(i,1,mid-1) ans-=2ll*xx[i].first+2ll*yy[i].first;
		FOR(i,mid+1,n) ans+=2ll*xx[i].first+2ll*yy[i].first;
		int at=-1;
		FOR(i,1,n) if(x[i]==xx[mid].first && y[i]==yy[mid].first) at=i;
		bool c1=false,c2=false;
		FOR(i,1,n) if(i!=at){
			if((x[i]<=xx[mid].first)^(y[i]<=yy[mid].first)) c1=true;
			else c2=true;
		}
		if(~at && c1 && c2){
			int t1=min(xx[mid].first-xx[mid-1].first,xx[mid+1].first-xx[mid].first);
			int t2=min(yy[mid].first-yy[mid-1].first,yy[mid+1].first-yy[mid].first);
			ans-=2ll*min(t1,t2);
		}
	}
	else{
		int mid=n/2;
		bool c1=false,c2=false;
		FOR(i,1,n){
			if((x[i]<=xx[mid].first)^(y[i]<=yy[mid].first)) c1=true;
			else c2=true;
		}
		FOR(i,1,mid) ans-=2ll*xx[i].first+2ll*yy[i].first;
		FOR(i,mid+1,n) ans+=2ll*xx[i].first+2ll*yy[i].first;
		if(c1 && c2){
			int t1=xx[mid+1].first-xx[mid].first;
			int t2=yy[mid+1].first-yy[mid].first;
			ans-=2ll*min(t1,t2);
		}
	}
	printf("%lld\n",ans);
}