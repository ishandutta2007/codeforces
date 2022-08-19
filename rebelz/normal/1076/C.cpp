#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

double t,n,x;

int main(){
	t=readint();
	while(t--){
		n=readint();
		if(n*n-4*n<0) printf("N\n");
		else{
			x=sqrt(n*n-4*n);
			printf("Y %.10lf %.10lf\n",(n+x)/2,(n-x)/2);
		}
	}
	return 0;
}