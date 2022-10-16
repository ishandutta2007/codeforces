#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,m=300000,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,a[maxn];
ll ans,sum;
struct BIT{
	ll b[maxn];
	inline void update(int p,ll v){
		for(int i=p;i<=m;i+=i&-i) b[i]+=v;
	}
	inline ll query(int p){
		ll s=0;
		for(int i=p;i;i-=i&-i) s+=b[i];
		return s;
	}
}b1,b2;
int main(){
	read(n);
	FOR(i,1,n){
		read(a[i]);
		ans+=b1.query(a[i])+1ll*a[i]*(i-1);
		FOR(j,1,m/a[i]) ans-=a[i]*(b2.query(min(m,(j+1)*a[i]-1))-b2.query(j*a[i]-1))*j;
		ans+=sum;
		FOR(j,1,m/a[i]) b1.update(a[i]*j,-a[i]);
		b2.update(a[i],1);
		sum+=a[i];
		printf("%lld ",ans);
	}
}