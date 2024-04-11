#include <iostream>
using namespace std;
int main(){
	bool f=1;
	string s,a=".";
	cin>>s;
	for (int i=0; i<s.size(); i++){
		if (s[i]!='a' and s[i]!='y' and s[i]!='i' and s[i]!='u' and s[i]!='o' and s[i]!='e' and s[i]!='A' and s[i]!='I' and s[i]!='Y' and s[i]!='U' and s[i]!='O' and s[i]!='E' ){
			if (int(s[i])<=int('z') and int(s[i])>=int('a')){
				a+=s[i];
				a+='.';
			}
			else{
				a+=char(int(s[i])-int('A')+int('a'));
				a+='.';
			}
		}	
	}
	a.erase(a.size()-1,a.size());
	cout<<a;
}