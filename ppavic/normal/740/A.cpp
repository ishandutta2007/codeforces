#include <cstdio>
#include <algorithm>

using namespace std;

long long int n,a,b,c,x;

int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
	x = 4 - n%4;
	if(x == 4 || x == 0){
		printf("0\n",0);
	}
	if(x == 1){
		printf("%I64d\n",min(a,min(b+c,c*3)));
	}
	if(x == 2){
		printf("%I64d\n",min(b,min(c*2,a*2)));
	}
	if(x == 3){
		printf("%I64d\n",min(c,min(a*3,b+a)));
	}
	
}