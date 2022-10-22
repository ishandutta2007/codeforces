#include<string.h>
#include<iostream>
using namespace std; 
int gcd(int a,int b){
	return a ? gcd(b%a,a) : b;
}
int main(){
	int n,t,ans=0;
	cin>>n;
	for(int i=2;i<n;i++){
		t=n;
		while(t!=0){
			ans+=t%i;t/=i;
		}
	}
	int p=gcd(ans,n-2);
	cout<<ans/p<<'/'<<(n-2)/p;
	return 0;
}