#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int maxn=1<<21,mod=998244353;
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
int n,lim;
ull a[maxn],b[maxn];
char s[maxn];
int main(){
	n=read();lim=1<<n;
	scanf("%s",s);
	FOR(i,0,lim-1) a[i]=ll(s[i]-'0')<<(2*__builtin_popcount(i));
	scanf("%s",s);
	FOR(i,0,lim-1) b[i]=ll(s[i]-'0')<<(2*__builtin_popcount(i));
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) a[i+j+k]+=a[j+k],b[i+j+k]+=b[j+k];
	FOR(i,0,lim-1) a[i]*=b[i];
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) a[i+j+k]-=a[j+k];
	FOR(i,0,lim-1) printf("%d",int((a[i]>>(2*__builtin_popcount(i)))&3));
}