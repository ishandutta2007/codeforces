#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long ans,k,n;
long long s(long long a){
	long long p=0;
	while(a>0){
		p+=a%10;
		a/=10;
	}
	return p;
}
long long f(long long n){
	if(n<10)return 0;
	long long p=0;
	while(n>=10){
		p=p*10+9;
		n/=10;
	}
	return p;
}
int main(){
	cin>>n;
	k=f(n);
	ans=s(k)+s(n-k);
	cout<<ans;
	return 0;
}