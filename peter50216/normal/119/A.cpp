#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    int c=0;
    while(n){
	if(c==0)n-=__gcd(n,a);
	else n-=__gcd(n,b);
	c=1-c;
    }
    printf("%d\n",1-c);
}