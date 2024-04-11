#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxp=130+5;
int n,p,q,a[maxp];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
typedef unsigned int uint;
uint c[maxp];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();
	p=read();
	q=read();
	for(int i=0;i<=min(p,n-1);i++){
		for(int j=0;j<i;j++) a[j]=n-j;
		for(int j=1;j<=i;j++){
			int b=j;
			for(int k=0;k<i;k++){
				int d=gcd(a[k],b);
				a[k]/=d;
				b/=d;
			}
		}
		c[i]=1;
		for(int j=0;j<i;j++) c[i]*=a[j];
	}
	uint out=0;
	for(int i=1;i<=q;i++){
		uint res=0,pw=1;
		for(int j=0;j<=min(p,n-1);j++){
			res+=c[j]*pw;
			pw*=i;
		}
		out^=res*i;
	}
	printf("%u\n",out);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}