#include<cstdio>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a==2&&b==0) {puts("NO"); return 0;}
	puts("YES");
	if(a==1) {printf("%d",b); return 0;}
	if(a==2) {printf("0 %d",b); return 0;}
	if(a==3) {if(b==0) printf("1 2 3"); else if(b==1) printf("5 6 2"); else printf("0 1 %d",b^1); return 0;}
	for(int i=1;i<=a-3;++i){
		printf("%d ",i); b^=i;
	}
	if(b==0) printf("%d %d %d",1+((1<<17)+(1<<18)),2+(1<<17),3+(1<<18));
	else if(b==1) printf("%d %d %d",5+((1<<17)+(1<<18)),6+(1<<17),2+(1<<18));
	else printf("%d %d %d",((1<<17)+(1<<18)),1+(1<<17),(b^1)+(1<<18));
	return 0;
}