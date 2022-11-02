#include <iostream>
using namespace std;
int a[100000];
int main(){
	int n,tp,t;
	tp=0;
	cin>>n;
	t=0;
	for (int i=0; i<n; i++){
		int z;
		cin>>z;
		if (z!=-1){
			tp+=z;
		}
		if (z==-1){
			tp-=1;
		}
		if (tp<0 && z==-1){
			t+=1;
		}
		if (tp<0){
			tp=0;
		}
	}
	cout<<t;	
}