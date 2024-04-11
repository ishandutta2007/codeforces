#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,t1=0,t2=0;
	cin>>n;
	for (int i=0; i<n; i++){
		char c;
		cin>>c;
		if (c=='1'){
			t1++;
		}
		else{
			t2++;
		}
	}
	cout<<abs(t1-t2);
}