#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define LL long long

LL n,m,ans;

LL pow(int x,int s){
	if (s==0) return 1;
	if (s==1) return x%10;
	LL tmp=pow(x*x%10,s/2);
	if (s&1) return tmp*tmp&x%10;
	else return tmp*tmp%10;
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	ans=1;
	for (LL i=0;i<=9;i++){
		LL tmp=0;
		if (m%10>=i) tmp+=m/10+1; else tmp+=m/10;
		if (n%10>=i) tmp-=n/10+1; else tmp-=n/10;
		ans=ans*pow(i,tmp)%10;
	}
	printf("%I64d\n",ans);
	
	return 0;
}