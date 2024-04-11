#include <cstdio>

using namespace std;

int n;
int sol[4] = {6,8,4,2};

int main(){
	scanf("%d",&n);
	if(n == 0){
		printf("1\n");
	}
	else{
		printf("%d\n",sol[n%4]);
	}
	
}