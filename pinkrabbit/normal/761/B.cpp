#include<cstdio>
int n,l;
int a[50];
int b[50];
void init(){
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
	for(int i=0;i<n;++i)
		scanf("%d",b+i);
}
int main(){
	init();
	for(int p=0;p<l;++p){
		for(int i=0;i<n;++i){
			int ok=1;
			for(int j=0;j<n;++j){
				if((a[j]+p)%l!=b[(j+i)%n]){
					ok=0;
					break;
				}
			}
			if(ok==1){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}