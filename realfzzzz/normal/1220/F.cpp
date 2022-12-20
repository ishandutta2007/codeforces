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
const int maxn=2e5+5;
int n,a[maxn],s[maxn],tp,d[maxn],f[maxn],g[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=0;i<n;i++) a[i]=read()-1;
	int x=0;
	while(a[x]) x++;
	s[tp=0]=x;
	for(int i=(x+1)%n;i!=x;i=(i+1)%n){
		d[i]=0;
		while(tp&&a[i]<a[s[tp]]) d[i]=max(d[i],d[s[tp--]]+1);
		f[i]=max(f[s[tp]],d[i]=max(d[i],tp+1));
		s[++tp]=i;
	}
	tp=0;
	for(int i=(x-1+n)%n;i!=x;i=(i-1+n)%n){
		d[i]=0;
		while(tp&&a[i]<a[s[tp]]) d[i]=max(d[i],d[s[tp--]]+1);
		g[i]=max(g[s[tp]],d[i]=max(d[i],tp+1));
		s[++tp]=i;
	}
	int mn=x;
	for(int i=(x+1)%n;i!=x;i=(i+1)%n)
		if(max(f[i],g[(i+1)%n])<max(f[mn],g[(mn+1)%n])) mn=i;
	printf("%d %d\n",max(f[mn],g[(mn+1)%n])+1,(mn+1)%n);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}