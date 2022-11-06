#include<cstdio>
int n,f[10000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&f[i]);
	for(int i=1;i<=n;++i){
		int a=i,b=f[a],c=f[b];
		if(a!=b&&b!=c&&a!=c&&f[c]==a){
			printf("YES"); return 0;
		}
	}
	printf("NO");
}