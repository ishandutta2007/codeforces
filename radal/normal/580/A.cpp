#include <iostream>
using namespace std;
int main(){
	int n,b=1;
	cin>>n;
	long int a[n];
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int t=1;
	for (int i=0; i<n-1; i++){
		if (a[i]<=a[i+1]){
			t+=1;	
		}
		else{
			if (t>b){
				b=t;
			}
			t=1;
		}
	}
	if (t>b){
		b=t;
	}
	cout<<b;
}