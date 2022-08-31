#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long n,m;
long long p[6]={0,0,0,0,2,4};

int main(){
	cin>>n>>m;
	if(n>m)
		swap(n,m);
	if(n<3&&m<3)
		cout<<0<<endl;
	else if(n==1){
		long long ans=n*m;
		if(m/6>=1)
			ans-=m%6-p[m%6];
		else
			ans=p[m];
		cout<<ans<<endl;
	}
	else if(n==2&&m==3)
		cout<<4<<endl;
	else if(n==2&&m==7)
		cout<<12<<endl;
	else
		cout<<n*m-n*m%2<<endl;
	return 0;
}