#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
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
int p[200010],P[200010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi();ll ans1=0,ans2=1;
	for(int i=1;i<=n;++i)p[gi()]=i;
	int o=0;
	for(int i=n;i>=n-k+1;--i)ans1+=i,P[++o]=p[i];
	std::sort(P+1,P+o+1);
	for(int i=1;i<o;++i)ans2=1ll*ans2*(P[i+1]-P[i])%mod;
	printf("%lld %d\n",ans1,ans2);
	return 0;
}