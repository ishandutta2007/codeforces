#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,a,b,j;
	bool f=0;
	cin>>n;
	a=0;
	for (int i=0; i<n; i++){
		b=a;
		cin>>a;
		if (b+15<a and f!=1){
			f=1;
			j=b+15;
		}
	}
	if (a+15<90 and f!=1){
		f=1;
		j=a+15;
	}
	if (f){
		cout<<j;
	}
	else{
		cout<<90;
	}
	return 0;
}