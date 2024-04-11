#include<cstdio>
const int maxn=30000;
bool f[maxn+10];
int n,t;
int main(){
	scanf("%d%d",&n,&t); f[1]=1;
	for(int i=1;i<n;++i){
		int x; scanf("%d",&x); f[i+x]|=f[i];
	}
	printf("%s",f[t]?"YES":"NO"); return 0;
}