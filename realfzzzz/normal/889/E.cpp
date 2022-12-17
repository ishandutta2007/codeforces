#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n=read();
	map<ll,ll> f;
	f[read()-1]=0;
	for(int i=2;i<=n;i++){
		ll a=read();
		map<ll,ll> f2;
		auto it=f.lower_bound(a);
		for(auto j=it;j!=f.end();j++){
			ll x=j->first,y=j->second;
			f2[x%a]=max(f2[x%a],y+(x-x%a)*(i-1));
			f2[a-1]=max(f2[a-1],y+(x-a+1)/a*a*(i-1));
		}
		f.erase(it,f.end());
		for(auto j:f2)
			f[j.first]=max(f[j.first],j.second);
	}
	ll ans=0;
	for(auto i:f) ans=max(ans,i.second+i.first*n);
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}