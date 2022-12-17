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
const int maxn=500+5;
int n,p[maxn][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) p[i][i]=read();
	for(int i=1;i<=n;i++){
		for(int j=i;p[j][j-i+1]!=i;j++) p[j+1][j-i+1]=p[j][j-i+1];
		for(int j=n;p[j][j-i+1]!=i;j--) p[j][j-i]=p[j][j-i+1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) printf("%d ",p[i][j]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}