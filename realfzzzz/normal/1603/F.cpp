#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const ll mod=998244353,inv2=499122177;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
const int maxk=1e7+5;
ll s[maxk];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		int n,k,x;
		n=readint();
		k=readint();
		x=readint();
		if(x){
			ll pw1=1;
			for(int i=k;i>0;i--){
				s[i]=(pw1-1+mod)%mod;
				pw1=pw1*2%mod;
			}
			s[0]=1;
			for(int i=1;i<=k;i++) s[i]=s[i]*s[i-1]%mod;
			ll ans=0,pw2=ksm(2,n),pw3=1;
			pw1=1;
			for(int i=k-1;i>=0;i--){
				ans=(ans+pw3*s[i]%mod*pw1%mod*(i%2==0?1:mod-1)%mod)%mod;
				pw1=pw1*2%mod;
				pw3=pw3*pw2%mod;
			}
			printf("%lld\n",ans);
		}
		else if(n>k) printf("0\n");
		else{
			ll ans=1,pw1=ksm(2,k),pw2=1;
			for(int i=0;i<n;i++){
				ans=(pw1-pw2+mod)%mod*ans%mod;
				pw2=pw2*2%mod;
			}
			printf("%lld\n",ans);
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}