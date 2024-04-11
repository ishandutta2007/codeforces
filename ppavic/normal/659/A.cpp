#include <cstdio>
#include <cstdlib>

using namespace std;

int n,a,b;

int main(){
	scanf("%d %d %d",&n,&a,&b);
	for(int i = 0;i<abs(b);i++){
		if(b>0) a++;
		else a--;
		if(a == 0) a = n;
		if(a == n+1) a = 1;
	}
	printf("%d",a);

}