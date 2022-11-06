#include <cstdio>
const int Maxn=1000;
int n;
int x;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		bool all=1,one=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			if(a[i]!=x){
				all=0;
			}
			if(a[i]==x){
				one=1;
			}
		}
		if(all){
			puts("0");
		}
		else if(sum==x*n){
			puts("1");
		}
		else{
			if(one){
				puts("1");
			}
			else{
				puts("2");
			}
		}
	}
	return 0;
}