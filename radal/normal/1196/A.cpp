#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	long long int j[t];
	for (int i=0; i<t; i++){
		long long int a,b,c;
		cin>>a>>b>>c;
		j[i]=(a+b+c)/2;
	}
	for (int i=0; i<t; i++){
		cout<<j[i]<<endl;
	}
}