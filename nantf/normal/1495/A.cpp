#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
int n,x[maxn],y[maxn],xl,yl;
void clear(){
	xl=yl=0;
}
void solve(){
	n=read();
	FOR(i,1,2*n){
		int xx=read(),yy=read();
		if(!yy) x[++xl]=abs(xx);
		else y[++yl]=abs(yy);
	}
	sort(x+1,x+xl+1);
	sort(y+1,y+yl+1);
	long double ans=0;
	FOR(i,1,n){
		ans+=sqrt((long double)(1ll*x[i]*x[i]+1ll*y[i]*y[i]));
	}
	cout<<fixed<<setprecision(15)<<ans<<endl; 
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}