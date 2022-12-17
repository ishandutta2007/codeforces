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
const int maxn=2e5+5,maxa=1e6+5;
bool np[maxa];
vector<int> p;
int n,e,a[maxn],f[maxn],g[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	np[1]=1;
	for(int i=2;i<maxa;i++){
		if(!np[i]) p.push_back(i);
		for(int j:p){
			if(1ll*i*j>=maxa) break;
			np[i*j]=1;
			if(i%j==0) break;
		}
	}
	int T=readint();
	while(T--){
		n=readint();
		e=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		ll ans=0;
		for(int i=1;i<=n;i++)
			f[i]=i<=e||a[i-e]!=1?0:f[i-e]+1;
		for(int i=n;i>0;i--)
			g[i]=i>n-e||a[i+e]!=1?0:g[i+e]+1;
		for(int i=1;i<=n;i++)
			if(!np[a[i]]) ans+=1ll*(f[i]+1)*(g[i]+1)-1;
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}