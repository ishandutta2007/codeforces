#include <iostream>
using namespace std;
int main(){
	int n,t=0;
	cin>>n;
	int j[n];
	t=n/2;
	cout<<t<<endl;
	if (n%2==0){
		for (int i=0; i<t; i++){
			cout<<2<<' ';
		}
	}
	if (n%2==1){
		for (int i=0; i<t-1; i++){
			cout<<2<<' ';
		}
		cout<<3;
	}
}