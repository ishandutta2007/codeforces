#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
#define fi first
#define se second
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],lt[maxn],cnt;
ll s[maxn],st[2][19][maxn];
map<ll,int> id;
vector<int> p[2][maxn];
void clear(){
	FOR(i,0,lt[n]) FOR(j,0,n) st[0][i][j]=st[1][i][j]=0;
	FOR(i,0,n) a[i]=s[i]=lt[i]=0;
	FOR(i,1,cnt) p[0][i].clear(),p[1][i].clear();
	cnt=0;
	id.clear();
}
inline ll query(ll st[][maxn],int l,int r){
	int k=lt[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
inline int getcnt(vector<int> &v,int l,int r){
	return lower_bound(v.begin(),v.end(),r+1)-lower_bound(v.begin(),v.end(),l);
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read(),s[i]=a[i]-s[i-1];
	FOR(i,0,n){
		if(!id.count(s[i])) id[s[i]]=++cnt;
		p[i%2][id[s[i]]].PB(i);
	}
	lt[0]=-1;
	FOR(i,1,n) lt[i]=lt[i>>1]+1;
	FOR(i,1,n){
		st[0][0][i]=st[1][0][i]=1e18;
		st[i%2][0][i]=s[i];
	}
	FOR(_,0,1) FOR(i,1,lt[n]) FOR(j,1,n-(1<<i)+1) st[_][i][j]=min(st[_][i-1][j],st[_][i-1][j+(1<<(i-1))]);
	ll ans=0;
//	FOR(i,1,n) printf("s[%d]=%lld\n",i,s[i]);
	FOR(i,1,n){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(query(st[i%2],i,mid)>=-s[i-1] && query(st[(i%2)^1],i,mid)>=s[i-1]) l=mid;
			else r=mid-1;
		}
//		printf("i=%d,r=%d\n",i,r);
		ans+=getcnt(p[i%2][id[-s[i-1]]],i,r)+getcnt(p[(i%2)^1][id[s[i-1]]],i,r);
	}
	printf("%lld\n",ans);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}