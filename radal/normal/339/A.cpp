#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string s,a="";
	int t=0;
	cin>>s;
	string c;
	for (int i=0; i<s.size(); i++){
		if (s[i]!='+'){
			c+=s[i];
			t+=1;
		}
	}
	sort(c.begin(),c.end());
	a+=c[0];
	for (int i=1; i<c.size(); i++){
		a+='+';
		a+=c[i];
	}
	cout<<a;
}