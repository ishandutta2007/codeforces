#include <iostream>
using namespace std;
bool aval(int n){
	int t=1;
	for (int i=2; i<n; i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	long long int n,t=0;
	cin>>n;
	int a[n];
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		a[x-1]=i+1;
	}
	for (int i=0; i<n; i++){
		cout<<a[i]<<' ';
	}
}