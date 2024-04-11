#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int n;

int main(){
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int b=sqrt(n);
	while(n>0){
		n-=b;
		for(int i=max(1,n+1);i<=n+b;i++)
			cout<<i<<' ';
	}
	return 0;
}