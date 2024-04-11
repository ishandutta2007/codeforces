#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n=readint(),cnt=0,prod=1;
	for(int i=1;i<n;i++) if(gcd(i,n)==1){
		cnt++;
		prod=1ll*prod*i%n;
	}
	printf("%d\n",cnt-(prod!=1));
	printf("1");
	for(int i=2;i<n;i++) if(gcd(i,n)==1&&i!=prod) printf(" %d",i);
	return 0;
}