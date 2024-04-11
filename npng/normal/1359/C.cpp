#include <cmath>
#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int h,c,t;
		scanf("%d%d%d",&h,&c,&t);
		if(h==t){
			puts("1");
			continue;
		}
		if((t<<1)<=h+c){
			puts("2");
			continue;
		}
		double x=1.0*(t-h)/(h+c-(t<<1));
		int x_1=floor(x),x_2=ceil(x);
		double ans_1=(1.0*h*(x_1+1)+1.0*c*x_1)/(2.0*x_1+1);
		double ans_2=(1.0*h*(x_2+1)+1.0*c*x_2)/(2.0*x_2+1);
		if(fabs(ans_1-t)<=fabs(ans_2-t)){
			printf("%d\n",x_1*2+1);
		}
		else{
			printf("%d\n",x_2*2+1);
		}
	}
	return 0;
}