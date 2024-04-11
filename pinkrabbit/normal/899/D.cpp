#include<cstdio>
int n;
long long sum;
long long check(int x){
	sum=0;
	long long ss=1,s2;
	while(x){
		ss*=10;
		--x;
	}
	s2=ss-1;
	for(int i=1;i<=9;++i){
		if(s2<=n) sum+=s2/2;
		else if(s2/2+1<=n) sum+=n-s2/2;
		else sum+=0;
		s2+=ss;
	}
	return sum;
}
int main(){
	scanf("%d",&n);
	if(n==2) {printf("1"); return 0;}
	if(n==3) {printf("3"); return 0;}
	if(n==4) {printf("6"); return 0;}
	for(int num=9;num>=0;--num){
		if(check(num)) {printf("%I64d",sum); return 0;}
	}
	return 0;
}