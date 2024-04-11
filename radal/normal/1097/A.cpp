#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t=0,n;
	string c,k="NO";
	cin>>c;
	for (int i=0; i<5; i++){
		string x;
		cin>>x;
		if (x[0]==c[0]){
			k="YES";
		}
		if (x[1]==c[1]){
			k="YES";
		}
	}
	cout<<k;
}