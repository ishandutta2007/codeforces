#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int t=gi();
	while(t--){
		ll n=gi(),s=(n-1)%3+1;
		n=(n-1)/3;
		ll A=0,B=0,w=2;
		for(int i=0;;i+=2)if(n>=(1ll<<i))n-=1ll<<i,w+=2;else break;
		A=(1ll<<w-2)+n;
		ll W;
		B=1ll<<w-1;
		for(int i=0;i<w-1;++i){
			W=1ll<<(i&~1)+1;
			if(~i&1){
				if(n%(W<<1)>=W)B|=1ll<<i;
			}else{
				if(n%(W<<1)>=(W>>1)&&n%(W<<1)<(W>>1)*3)B|=1ll<<i;
			}
		}
		printf("%lld\n",s==1?A:s==2?B:A^B);
	}
	return 0;
}