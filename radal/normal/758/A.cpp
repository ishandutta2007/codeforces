#include <iostream>
using namespace std;
int main(){
	int n,b=0,j=0,m=0;
	cin>>n;
	int t[n];
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		t[i]=x;
	}
	b=t[0];
	for (int i=0; i<n; i++){
		if (t[i]>b){
			b=t[i];
			j=i;
		}
	}
	for (int i=0; i<n; i++){
		m+=b-t[i];
	}
	cout<<m;
}