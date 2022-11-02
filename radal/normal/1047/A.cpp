#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long int n;
	int t=1;
	cin>>n;
	if (n%3==0){
		cout<<1<<' '<<1<<' '<<n-2;
		return 0;
	}
	if (n%3==1){
		cout<<1<<' '<<2<<' '<<n-3;
	}
	if (n%3==2){
		cout<<2<<' '<<2<<' '<<n-4;
	}
	return 0;

}