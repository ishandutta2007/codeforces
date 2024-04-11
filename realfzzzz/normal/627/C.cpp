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
const int maxm=2e5+5;
int d,n,m,x[maxm],p[maxm];
int ord[maxm],s[maxm],tp=0,nxt[maxm];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	d=readint();
	n=readint();
	m=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint();
		p[i]=readint();
	}
	for(int i=1;i<=m+1;i++) ord[i]=i;
	sort(ord+1,ord+m+1,[](int a,int b){
		return x[a]<x[b];
	});
	s[0]=m+1;
	x[m+1]=d;
	for(int i=m;i>0;i--){
		int u=ord[i];
		while(tp&&p[u]<p[s[tp]]) tp--;
		nxt[u]=s[tp];
		s[++tp]=u;
	}
	int c=n;
	ll ans=0;
	for(int i=1;i<=m+1;i++){
		int u=ord[i];
		c-=x[u]-x[ord[i-1]];
		if(c<0){
			printf("-1\n");
			return 0;
		}
		if(i==m+1) break;
		if(x[u]+c<x[nxt[u]]){
			int t=min(x[nxt[u]]-x[u],n);
			ans+=1ll*(t-c)*p[u];
			c=t;
		}
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}