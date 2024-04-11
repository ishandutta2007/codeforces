#include <iostream>
using namespace std;
int main(){
	int d1,d2,d3,min=300000000;
	cin>>d1>>d2>>d3;
	min=d1+d2+d3;
	if (2*(d1+d2)<min){
		min=2*(d1+d2);
	}
	if(2*(d1+d3)<min){
		min=2*(d1+d3);
	}
	if (2*(d2+d3)<min){
		min=2*(d2+d3);
	}
	cout<<min;
}