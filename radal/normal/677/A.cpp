#include <iostream>
#include <algorithm>
using namespace std;
string add(int a){
	string s="";
	while (a!=0){
		s+=char(a%10+int('0'));
		a/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	int t=0,n,h;
	cin>>n>>h;
	for (int i=0; i<n; i++){
		int a;
		cin>>a;
		if (a>h){
			t+=1;
		}
	}
	cout<<2*t+n-t;
}