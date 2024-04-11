#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long n,m,a,b;

int main(){
	cin>>n>>m>>a>>b;
	if((n+m)%m==0){
		cout<<0<<endl;
		return 0;
	}
	long long x=n/m;
	cout<<min((n-x*m)*b,((x+1)*m-n)*a)<<endl;
	return 0;
}