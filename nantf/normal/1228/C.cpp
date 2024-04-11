#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=1000000007;
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
int x,num[maxn],len,ans=1;
ll n;
int calc(int x){
	int ans=0;
	ll pr=x;
	while(true){
		ans=(ans+n/pr)%(mod-1);
		ll pre=pr;
		pr*=x;
		if(pr/pre!=x || pr>n) break;
	}
	return ans;
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	x=read();n=read();
	for(int i=2;i*i<=x;i++) if(x%i==0){
		num[++len]=i;
		while(x%i==0) x/=i;
	}
	if(x>1) num[++len]=x;
	FOR(i,1,len){
		int x=num[i];
		ans=1ll*ans*qpow(x,calc(x))%mod;
	}
	printf("%d\n",ans);
}