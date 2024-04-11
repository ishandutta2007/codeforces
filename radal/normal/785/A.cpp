#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int b,t=0;
	cin>>b;
	for (int i=0; i<b; i++){
		string s;
		cin>>s;
		if (s=="Tetrahedron"){
			t+=4;
		}
		if (s=="Cube"){
			t+=6;
		}
		if (s=="Octahedron" ){
			t+=8;
		}
		if (s=="Dodecahedron"){
			t+=12;
		}
		if (s=="Icosahedron"){
			t+=20;
		}
	}
	cout<<t;
}