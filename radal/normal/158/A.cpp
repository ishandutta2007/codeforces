#include <iostream>
using namespace std;
int main(){
	int n,k,t=0;
	cin>>n>>k;
	int a[n];
	for (int i=0; i<n; i++){
		int b;
		cin>>b;
		a[i]=b;
	}
	for (int i=0; i<n; i++){
		if (a[i]>=a[k-1] and a[i]>0){
			t+=1;
		}
	}
	cout<<t;
}