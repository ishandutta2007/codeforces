#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	long int a[t];
	for (int i=0; i<t; i++){
		int hh,mm;
		cin>>hh>>mm;
		a[i]=(23-hh)*60+60-mm;
	}
	for (int i=0; i<t; i++){
		cout<<a[i]<<endl;
	}
}