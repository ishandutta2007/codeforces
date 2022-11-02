#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,z;
	const char* a[6];
	a[0]="Sheldon";
	a[1]="Leonard";
	a[2]="Penny";
	a[3]="Rajesh";
	a[4]="Howard";
	cin>>n;
	z=1;
	for (int i=0; i<n; i++){
		a[5]=a[0];
		a[0]=a[1];
		a[1]=a[2];
		a[2]=a[3];
		a[3]=a[4];
		a[4]=a[5];
		if (a[4]=="Sheldon" && i!=0){
			z*=2;
		}	
		i+=z-1;
	}
	cout<<a[4];
}