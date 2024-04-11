#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
	long long t,n,a,b,c;
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c;
		cout<<n/(a*c)*(a+b)+n%(a*c)/c<<endl;
	}
	return 0;
}