#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n;
char s[maxn];
void solve(){
	read(n);
	scanf("%s",s+1);
	int c0=0,c1=0;
	FOR(i,1,n){
		if(s[i]=='0') c0++;
		if(s[i]=='1' && i<n && s[i+1]=='1') c1++,i++;
	}
	int ans=1;
	FOR(i,1,c0+c1) ans=1ll*ans*i%mod;
	FOR(i,1,c0) ans=1ll*ans*qpow(i,mod-2)%mod;
	FOR(i,1,c1) ans=1ll*ans*qpow(i,mod-2)%mod;
	printf("%d\n",ans);
}
int main(){
	int T;
	read(T);
	while(T--) solve();
}