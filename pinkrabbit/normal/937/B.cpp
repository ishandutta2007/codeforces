#include<cstdio>
int p,y;
int main(){
	scanf("%d%d",&p,&y);
	for(int i=y;i>p;--i){
		for(int j=2;j<=p&&j*j<=i;++j) if(i%j==0) goto no;
		printf("%d",i); return 0;
		no: continue; 
	} puts("-1");
	return 0;
}