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
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		int n,m;
		n=read();
		m=read();
		if(n>m) printf("No\n");
		else if(n%2==1){
			printf("Yes\n");
			for(int i=1;i<n;i++) printf("1 ");
			printf("%d\n",m-n+1);
		}
		else if(m%2==1) printf("No\n");
		else{
			printf("Yes\n");
			for(int i=1;i<=n-2;i++) printf("1 ");
			printf("%d %d\n",(m-n+2)/2,(m-n+2)/2);
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}