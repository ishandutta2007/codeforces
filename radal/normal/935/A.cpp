#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long int n;
	int t=1;
	cin>>n;
	for (int i=2; i<n; i++){
		if (n%i==0){
			t+=1;
		}
	}
	cout<<t;
	return 0;

}