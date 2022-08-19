#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long n,m;

int main(){
	cin>>n>>m;
	if(m==0)
		cout<<n<<' '<<n<<endl;
	else{
		cout<<max(0ll,n-m*2)<<' ';
		for(long long i=1;i<=n;i++)
			if(i*(i-1)/2>=m){
				cout<<n-i<<endl;
				return 0;
			}
	}
	return 0;
}