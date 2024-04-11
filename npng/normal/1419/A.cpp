#include <cstdio>
#include <cstring>
const int Maxn=1000;
int n;
int a[Maxn+5];
int num[2][2];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof num);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%1d",&a[i]);
			num[i&1][a[i]&1]++;
		}
		if(n&1){
			if(num[1][1]>0){
				puts("1");
			}
			else{
				puts("2");
			}
		}
		else{
			if(num[0][0]>0){
				puts("2");
			}
			else{
				puts("1");
			}
		}
	}
	return 0;
}