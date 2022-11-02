#include <iostream>
using namespace std;
int a[2];
int main(){
	int z,n;
	cin>>n;
	z=1;
	a[0]=n/10;
	a[1]=n%10;
	if (a[0]==0){
		z*=2;
	}
	if (a[0]==1){
		z*=7;
	}
	if (a[0]==2){
		z*=2;
	}
	if (a[0]==3){
		z*=3;
	}
	if (a[0]==4){
		z*=3;
	}
	if (a[0]==5){
		z*=4;
	}
	if (a[0]==6){
		z*=2;
	}
	if (a[0]==7){
		z*=5;
	}
	if (a[0]==8){
		z*=1;
	}
	if (a[0]==9){
		z*=2;
	}
	if (a[1]==0){
		z*=2;
	}
	if (a[1]==1){
		z*=7;
	}
	if (a[1]==2){
		z*=2;
	}
	if (a[1]==3){
		z*=3;
	}
	if (a[1]==4){
		z*=3;
	}
	if (a[1]==5){
		z*=4;
	}
	if (a[1]==6){
		z*=2;
	}
	if (a[1]==7){
		z*=5;
	}
	if (a[1]==8){
		z*=1;
	}
	if (a[1]==9){
		z*=2;
	}
	cout<<z;
}