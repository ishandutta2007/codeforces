#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t=0,n;
	cin>>n;
	while (n!=0){
		t+=1;
		if (n>=100){
			n-=100;
			continue;
		}
		if (n<100 and n>=20){
			n-=20;
			continue;
		}
		if (n<20 and n>=10){
			n-=10;
			continue;
		}
		if (n<10 and n>=5){
			n-=5;
			continue;
		}
		if (n<5){
			n-=1;
			continue;
		}
	}
	cout<<t;
}