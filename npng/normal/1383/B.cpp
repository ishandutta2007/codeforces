#include <cstdio>
#include <cstring>
const int Maxn=100000;
int n;
int a[Maxn+5];
int num[35];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof num);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=29;j>=0;j--){
				if((a[i]>>j)&1){
					num[j]++;
				}
			}
		}
		int flag=0;
		for(int i=29;i>=0;i--){
			if(num[i]>0){
				if((num[i]&1)&&((n-num[i])&1)){
					flag=1;
					break;
				}
				if(num[i]&1){
					if((num[i]-1)%4==0){
						flag=1;
						break;
					}
					else{
						flag=-1;
						break;
					}
				}
			}
		}
		if(flag==1){
			puts("WIN");
		}
		else if(flag==-1){
			puts("LOSE");
		}
		else{
			puts("DRAW");
		}
	}
	return 0;
}