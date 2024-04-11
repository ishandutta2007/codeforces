#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long n,m;

int main(){
	cin>>n>>m;
	if(m<=n+1){
		cout<<(m-1)/2<<endl;
		return 0;
	}
	else if(n+n-1<m){
		cout<<0<<endl;
		return 0;
	}
	else{
		cout<<(min(m-1,n)-max(1ll,m-n)+1)/2<<endl;
	}
	return 0;
}