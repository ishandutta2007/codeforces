#include <cstdio>

using namespace std;

int n;

int main(){
	scanf("%d",&n);
	for(int i = 0;i*1234567<=n;i++){
		for(int j = 0;j*123456+i*1234567<=n;j++){
			if( (n - i*1234567 - j*123456) %1234==0){
				printf("YES\n");
				return 0;
			}

		}
	}
	printf("NO\n");

}