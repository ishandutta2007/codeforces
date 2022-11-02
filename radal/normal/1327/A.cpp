#include <iostream>
#include <cmath>
using namespace std;
long long int f(int n){
	if (n==0 || n==1)
	return 1;
	if (n>1){
		return n*f(n-1);
	}
}
int main(){
	int n,t,k;
	cin>>t;
	for (int i=0; i<t; i++){
		cin>>n>>k;
		if (n%2==k%2 && n>=pow(k,2)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}