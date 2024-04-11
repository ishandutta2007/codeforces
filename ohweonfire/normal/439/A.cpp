#include <stdio.h>
using namespace std;
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	int sum=n*10-10;
	for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			sum+=x;
			if(sum>d){printf("-1\n");return 0;}
	}
	printf("%d\n",(d-sum+n*10-10)/5);
	return 0;
}