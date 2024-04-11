#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
int n,cc[2][2];
ll ans;
inline ll c2(int x){
	return 1ll*x*(x-1)/2;
} 
inline ll c3(int x){
	return 1ll*x*(x-1)*(x-2)/6;
}
int main(){
	n=read();
	FOR(i,1,n){
		int x=read()/2%2,y=read()/2%2;
		cc[x][y]++;
	}
	FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) FOR(d,0,1) FOR(e,0,1) FOR(f,0,1){
		int x=(a^c)|(b^d),y=(a^e)|(b^f),z=(c^e)|(d^f);
		if(x^y^z) continue;
		x=a*2+b,y=c*2+d,z=e*2+f;
		if(x>y || y>z) continue;
		if(x==y && y==z) ans+=c3(cc[a][b]);
		else if(x==y) ans+=c2(cc[a][b])*cc[e][f];
		else if(y==z) ans+=cc[a][b]*c2(cc[e][f]);
		else ans+=1ll*cc[a][b]*cc[c][d]*cc[e][f];
	}
	printf("%lld\n",ans);
}