#include <iostream>
using namespace std;
int main(){
	int n,x,t;
	cin>>n;
	x=0;
	t=0;
	while (n>x){
	if (n-x<=2){
		t+=1;
		cout<<t;
		return 0;
	}
		if (t%2==0){
			x+=1;
		}
		else{
			x+=2;
		}
		t+=1;
	}
	cout<<t;
}