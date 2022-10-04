#include<cstdio>
int main(){
	long long a,b;
	scanf("%I64d%I64d",&a,&b);
	if(b-a>=10) puts("0");
	else{
		int last=1;
		for(long long c=a+1;c<=b;++c) last=last*(c%10);
		printf("%d",last%10);
	}
	return 0;
}