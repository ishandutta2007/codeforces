#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct envelope{
	int s,t,d,w;
	bool operator<(const envelope &e)const{
		if(w!=e.w) return w>e.w;
		return d>e.d;
	}
	void input(){
		s=read();t=read();d=read();w=read();
	}
}en[maxn],tk[maxn];
bool cmp1(envelope e1,envelope e2){
	return e1.s<e2.s;
}
int n,m,k;
ll dp[maxn][222];
multiset<envelope> mst;
int main(){
	n=read();m=read();k=read();
	FOR(i,1,k) en[i].input();
	sort(en+1,en+k+1,cmp1);
	int cur=1;
	FOR(i,1,n){
		while(cur<=k && en[cur].s<=i) mst.insert(en[cur++]);
		while(!mst.empty() && mst.begin()->t<i) mst.erase(mst.begin());
		if(!mst.empty()) tk[i]=*mst.begin();
	}
	MEM(dp,0x3f);
	dp[0][0]=0;
	FOR(i,0,n) FOR(j,0,min(i,m)){
		dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
		if(tk[i].d) dp[tk[i].d+1][j]=min(dp[tk[i].d+1][j],dp[i][j]+tk[i].w);
		else dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
	}
	ll ans=LLONG_MAX;
	FOR(j,0,m) ans=min(ans,dp[n+1][j]);
	printf("%lld\n",ans);
}