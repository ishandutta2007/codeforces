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
const int maxn=250+5;
int n,c[maxn*2][maxn*2];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n*2;i++) for(int j=1;j<=n*2;j++) c[i][j]=readint();
		ll s=0;
		for(int i=n+1;i<=n*2;i++) for(int j=n+1;j<=n*2;j++) s+=c[i][j];
		printf("%lld\n",s+min({c[n][n+1],c[n+1][n],c[n][n*2],c[n*2][n],c[1][n*2],c[n*2][1],c[1][n+1],c[n+1][1]}));
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}