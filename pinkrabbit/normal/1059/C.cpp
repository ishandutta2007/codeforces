#include<cstdio>
// from_luogu
int n;
void f(int n,int x){
	if(n==1) printf("%d ",x);
	else if(n==2) printf("%d %d ",x,x*2);
	else if(n==3) printf("%d %d %d ",x,x,x*3);
	else{
		for(int i=1;i<=n-n/2;++i) printf("%d ",x);
		f(n/2,x*2);
	}
}
int main(){
	scanf("%d",&n);
	f(n,1);
	return 0;
}