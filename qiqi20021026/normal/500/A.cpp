#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,x;
bool f[120000];

int main(){
	scanf("%d%d",&n,&m);
	f[1]=1;
	for (int i=1;i<n;i++){scanf("%d",&x); f[i+x]|=f[i];}
	puts(f[m]?"YES":"NO");
	
	return 0;
}