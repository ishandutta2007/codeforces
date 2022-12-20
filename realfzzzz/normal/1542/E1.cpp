#include<bits/stdc++.h>
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
const int maxn=500+5;
int n;
typedef long long ll;
ll mod,f[maxn*maxn],s1[maxn*maxn],s2[maxn*maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	mod=readint();
	ll ans=0;
	f[0]=1%mod;
	for(int i=1;i<n;i++){
		s1[0]=f[0];
		for(int j=1;j<=i*(i-1)/2;j++){
			s1[j]=(s1[j-1]+f[j])%mod;
			s2[j]=(s2[j-1]+j*f[j]%mod)%mod;
		}
		for(int j=0;j<=i*(i-1)/2;j++){
			int r=min(j+i-1,i*(i-1)/2);
			f[j]=((s1[r]-s1[j]+mod)%mod*((i+j)%mod)%mod-s2[r]+s2[j]+mod)%mod;
			if(j-i+1>0)
				f[j]=(f[j]+(s1[j]-s1[j-i]+mod)%mod*(((i-j)%mod+mod)%mod)%mod+s2[j]-s2[j-i]+mod)%mod;
			else
				f[j]=(f[j]+(s1[j]+s1[i-j-1]-s1[0]+mod)%mod*((i-j)%mod)%mod+s2[j]-s2[i-j-1]+mod)%mod;
		}
		ll res=1%mod;
		for(int j=i+2;j<=n;j++) res=j%mod*res%mod;
		ll s=0;
		for(int j=i*(i-1)/2;j>i+1;j--) s=(s+f[j])%mod;
		for(int j=i;j>0;j--){
			s=(s+f[j+1])%mod;
			ans=(ans+(i+1-j)%mod*res%mod*s%mod)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}