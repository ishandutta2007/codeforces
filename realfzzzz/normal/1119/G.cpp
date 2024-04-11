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
const int maxn=1e6+5;
int n,m,a[maxn],s[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<m;i++) s[i]=(s[i-1]+a[i])%n;
	sort(s+1,s+m);
	s[m]=n;
	for(int i=m;i>1;i--) s[i]-=s[i-1];
	int t=0;
	for(int i=1;i<=m;i++) t+=a[i];
	printf("%d\n",t=(t-1)/n+1);
	for(int i=1;i<=m;i++) printf("%d ",s[i]);
	printf("\n");
	int x=1;
	while(t--){
		for(int i=1;i<=m;i++){
			if(x<m&&!a[x]) x++;
			printf("%d ",x);
			a[x]-=s[i];
		}
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}