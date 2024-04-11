#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,m,a[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
const ll inf=9e18;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int d=0;
		for(int i=1;i<=m;i++) d=gcd(d,read());
		ll s0=0,s1=0;
		for(int i=1;i<=d;i++){
			vector<int> vec;
			for(int j=i;j<=n;j+=d) vec.push_back(a[j]);
			sort(vec.begin(),vec.end());
			ll s=0;
			for(int j:vec) s+=j;
			ll mx0=-inf,mx1=s;
			for(int j=0;j<(int)vec.size();j++){
				s-=vec[j]*2;
				if(j%2==0) mx0=max(mx0,s);
				else mx1=max(mx1,s);
			}
			s0+=mx0;
			s1+=mx1;
		}
		printf("%lld\n",max(s0,s1));
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}