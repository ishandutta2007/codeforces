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
int n,a[maxn],mx[maxn],mn[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) mx[i]=max(mx[i-1],a[i]);
		mn[n+1]=2e9;
		for(int i=n;i>0;i--) mn[i]=min(mn[i+1],a[i]);
		bool flag=0;
		for(int i=1;i<n;i++) flag|=mx[i]>mn[i+1];
		printf(flag?"YES\n":"NO\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}