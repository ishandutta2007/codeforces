#include<string.h>
#include<iostream>
using namespace std;
char oper[10];
long long f2(long long a,long long b){
	if(oper[2]=='+')return a+b;else return a*b;
}
long long f3(long long a,long long b,long long c){
	long long ans=10000000000000000;
	if(oper[1]=='+'){
		ans=min(ans,f2(a+b,c));
		ans=min(ans,f2(a+c,b));
		ans=min(ans,f2(b+c,a));
	}else{
		ans=min(ans,f2(a*b,c));
		ans=min(ans,f2(a*c,b));
		ans=min(ans,f2(b*c,a));
	}
	return ans;
}
long long f4(long long a,long long b,long long c,long long d){
	long long ans=1000000000000000;
	if(oper[0]=='+'){
		ans=min(ans,f3(a+b,c,d));
		ans=min(ans,f3(a+c,b,d));
		ans=min(ans,f3(b+c,d,a));
		ans=min(ans,f3(b+d,a,c));
		ans=min(ans,f3(a+d,b,c));
		ans=min(ans,f3(c+d,a,b)); 
	}else{
		ans=min(ans,f3(a*b,c,d));
		ans=min(ans,f3(a*c,b,d));
		ans=min(ans,f3(b*c,d,a));
		ans=min(ans,f3(b*d,a,c));
		ans=min(ans,f3(a*d,b,c));
		ans=min(ans,f3(c*d,a,b)); 
	}
	return ans;
}
int main(){
	int i;
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	for(i=0;i<3;i++){
		cin>>oper[i]; 
	}
	long long ans=f4(a,b,c,d);
	cout<<ans;
	return 0;
}