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
	int n=read();
	if(n==1){
		printf("1\n1 1\n");
		return 0;
	}
	printf("%d\n",(n*2-2)/3+1);
	while(n%3!=2){
		printf("%d %d\n",n,n);
		n--;
	}
	for(int i=1;i<=n/3;i++) printf("%d %d\n",i,n/3+1-i);
	for(int i=1;i<=n/3+1;i++) printf("%d %d\n",n+1-i,n-n/3-1+i);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}