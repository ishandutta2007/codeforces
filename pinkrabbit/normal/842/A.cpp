#include<cstdio>
int l,r,x,y,k; 
int main(){
	scanf("%d%d%d%d%d",&l,&r,&x,&y,&k);
	for(int i=x;i<=y;++i){
		long long kk=1ll*i*k;
		if(l<=kk&&kk<=r) {puts("YES"); return 0;}
	}
	puts("NO");
	return 0;
}