#include <iostream>
using namespace std;
int main(){
	int x,t=0;
	cin>>x;
	if (x>4){
		t+=x/5;	
		x-=t*5;
	}
	//cout<<x;
	if (x>3){
		t+=x/4;
		x-=t*4;
	}
	if (x>2){
		t+=x/3;
		x-=t*3;
	}
	if (x>1){
		t+=x/2;
		x-=t*2;
	}
	if (x>0){
		t+=x;
		x-=t;
	}
	cout<<t;
}