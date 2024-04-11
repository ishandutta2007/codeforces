#include <iostream>
using namespace std;
int main(){
	bool f=1;
	string s,a;
	int ms=0,ma=0;
	cin>>s>>a;
	for (int i=0; i<s.size(); i++){
		if (int(s[i])<int('a')){
			s[i]=char(int(s[i])+32);
		}
		if (int(a[i])<int('a')){
			a[i]=char(int(a[i])+32);
		}
		if (a[i]>s[i]){
			cout<<-1;
			return 0;
		}
		if (a[i]<s[i]){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
}