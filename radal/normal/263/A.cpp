#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int x,y;
	for (int i=0; i<25; i++){
		int p;
		cin>>p;
		if (p==1){
			x=i/5;
			y=i%5;
		}
	}
	//cout<<x<<endl<<y<<endl;
	cout<<abs(2-x)+abs(2-y);
}