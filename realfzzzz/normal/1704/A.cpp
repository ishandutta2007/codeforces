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
const int maxn=50+5;
int n,m;
char a[maxn],b[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		scanf("%s%s",a+1,b+1);
		bool flag=0;
		for(int i=1;i<=n-m+1;i++) flag|=a[i]==b[1];
		for(int i=n-m+2;i<=n;i++) flag&=a[i]==b[i-n+m];
		printf(flag?"YES\n":"NO\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}