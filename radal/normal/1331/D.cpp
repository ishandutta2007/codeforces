#include <iostream>
using namespace std;
int main(){
	int n;
	for (int i=0; i<7; i++){
		char c;
		cin>>c;
		if (i==6){
			cout<<(int(c)-int('0'))%2;
		}
	}
}