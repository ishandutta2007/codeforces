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
const int maxn=300+5;
int n,l[maxn],c[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
map<int,ll> f[maxn];
const ll inf=9e18;
ll dfs(int x,int d){
	if(x==n+1) return d==1?0:inf;
	if(f[x].count(d)) return f[x][d];
	ll ans=dfs(x+1,d);
	if(l[x]%d!=0){
		ll res=dfs(x+1,gcd(d,l[x]));
		if(res<inf) ans=min(ans,res+c[x]);
	}
	return f[x][d]=ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) l[i]=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	ll ans=inf;
	for(int i=1;i<=n;i++){
		ll res=dfs(i+1,l[i]);
		if(res<inf) ans=min(ans,res+c[i]);
	}
	printf("%lld\n",ans<inf?ans:-1);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}