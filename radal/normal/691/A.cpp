#include <iostream>
using namespace std;
int main(){
	int n,t;
	cin>>n;
	t=0;
	if (n==1){
		int x;
		cin>>x;
		if (x==1){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		return 0;
	}
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		if (x==0){
			t+=1;
		}
	}
	if (t!=1){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
}