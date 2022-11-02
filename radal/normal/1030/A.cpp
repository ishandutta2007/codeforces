#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,z;
	char* flag;
	flag="EASY";
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>z;
		if (z==1){
			flag="HARD";
		}
	}
	cout<<flag;
}