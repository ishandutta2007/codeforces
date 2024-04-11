#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,tm=0,tc=0;
	cin>>n;
	for (int i=0; i<n; i++){
		int m,c;
		cin>>m>>c;
		if (m>c){
			tm+=1;
		}
		if (c>m){
			tc+=1;
		}
	}
	if (tm>tc){
		cout<<"Mishka";
	}
	if (tm<tc){
		cout<<"Chris";
	}
	if (tm==tc){
		cout<<"Friendship is magic!^^";
	}
}