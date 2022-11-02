#include<bits/stdc++.h>
using namespace std;
int n,m,f[100010];
int main(){
	scanf("%d%d",&n,&m);
	f[1]=2;
	f[2]=4;
	for (int i=3;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%1000000007;
	printf("%d\n",(f[n]+f[m]-2)%1000000007);
}