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
const int maxn=1e5+5;
int n,a[maxn];
const ll mod=998244353;
typedef pair<int,int> pii;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		ll ans=0;
		vector<pii> vec;
		for(int i=n;i>0;i--){
			vector<pii> res;
			for(pii x:vec){
				int c=(a[i]-1)/x.first+1;
				ans=(ans+1ll*(c-1)*x.second%mod*i%mod)%mod;
				if(res.size()&&a[i]/c==res.back().first) res.back().second+=x.second;
				else res.push_back({a[i]/c,x.second});
			}
			if(res.size()&&a[i]==res.back().first) res.back().second++;
			else res.push_back({a[i],1});
			vec=res;
		}
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}