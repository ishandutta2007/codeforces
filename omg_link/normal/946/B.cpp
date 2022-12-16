#include <stdio.h>
typedef long long LL;
LL a,b;
int d1(){
	if(a==0||b==0)return 0;
	else return 2;
}
int d2(){
	if(a>=2*b){a=a%(2*b);return 1;}
	else return 3;
}
int d3(){
	if(b>=2*a){b=b%(2*a);return 1;}
	else return 0;
}
int main(){
	scanf("%lld%lld",&a,&b);
	int ret=1;
	while(ret!=0){
		switch(ret){
			case 1:{ret=d1();break;}
			case 2:{ret=d2();break;}
			case 3:{ret=d3();break;}
		}
	}
	printf("%lld %lld",a,b);
}