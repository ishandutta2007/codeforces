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
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		int n=readint();
		ll k=readint();
		ll x1=readint(),d;
		d=abs(readint()-x1);
		for(int i=3;i<=n;i++) d=gcd(d,abs(readint()-x1));
		printf(abs(k-x1)%d==0?"YES\n":"NO\n");
	}
	return 0;
}