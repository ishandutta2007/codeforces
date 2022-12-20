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
const int maxn=1e4+5;
int n,c,p[maxn],s[maxn],ord[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	c=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) s[i]=read();
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return s[a]-p[a]-1ll*c*a<s[b]-p[b]-1ll*c*b;
	});
	ll res=0;
	for(int i=1;i<=n;i++) res+=p[i];
	ll ans=res;
	for(int i=1;i<=n;i++){
		int u=ord[i];
		ans=min(ans,res+=s[u]-p[u]+1ll*c*(n-u-i+1));
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}