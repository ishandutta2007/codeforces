#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=20+5;
int n;
char s[(1<<maxn)+5];
typedef long long ll;
ll f[(1<<maxn)+5];
const ll mod=1e9+7,inv2=500000004;
void FWT(ll* f,int n,bool flag){
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++){
			ll t=f[k+i];
			f[k+i]=(f[k]+mod-t)%mod*(flag?1:inv2)%mod;
			f[k]=(f[k]+t)%mod*(flag?1:inv2)%mod;
		}
}
ll ksm(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
int cnt[(1<<maxn)+5];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) f[i]=s[i]-'0';
	FWT(f,1<<n,1);
	for(int i=0;i<(1<<n);i++) f[i]=f[i]*f[i]%mod;
	FWT(f,1<<n,0);
	for(int i=1;i<(1<<n);i++) cnt[i]=cnt[i^(i&-i)]+1;
	ll ans=0;
	for(int i=0;i<(1<<n);i++) ans=(ans+f[i]*ksm(2,n-cnt[i])%mod)%mod;
	printf("%lld\n",ans*3%mod);
	return 0;
}