#include <iostream>
#include <string>
using namespace std;
int main(){
	long double v,m=0;
	long long int n1;
	string s;
	cin>>n1;
	for (int i=0; i<n1; i++){
		int x;
		cin>>x;
		m+=x;
	}
	v=m/n1;
	cout<<v;

}