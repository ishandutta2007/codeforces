#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a,i;
    scanf("%d",&a);
    int s=0;
    for(i=2;i<a;i++){
	int aa=a;
	while(aa){
	    s+=aa%i;
	    aa/=i;
	}
    }
    int g=__gcd(a-2,s);
    s/=g;
    printf("%d/%d\n",s,(a-2)/g);
}