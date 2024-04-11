#include<cstdio>
int n,m,z;
int gcd(int a,int b){return a%b?gcd(b,a%b):b;}
int main(){
	scanf("%d%d%d",&n,&m,&z);
	printf("%d",z/(n*m/gcd(n,m)));
	return 0;
}