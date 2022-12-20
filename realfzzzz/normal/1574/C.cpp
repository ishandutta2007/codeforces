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
int n,m;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	ll sum=0;
	multiset<ll> s;
	for(int i=1;i<=n;i++){
		ll a=readint();
		sum+=a;
		s.insert(a);
	}
	m=readint();
	while(m--){
		ll x,y;
		x=readint();
		y=readint();
		ll ans=9e18;
		if(*--s.end()>=x) ans=min(ans,max(y-sum+*s.lower_bound(x),0ll));
		if(*s.begin()<x){
			int res=*--s.upper_bound(x);
			ans=min(ans,x-res+max(y-sum+res,0ll));
		}
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}