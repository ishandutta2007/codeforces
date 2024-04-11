#include <string.h>
#include <iostream>
#include <set>
using namespace std;
string s;
set<char> t;
int main(){
	getline(cin,s);
	for(int i=0;i<s.size();i++){
			if(s[i]>='a'&&s[i]<='z')t.insert(s[i]);
			if(s[i]=='}')break;
	}
	cout<<int(t.size());
	//system("pause");
	return 0;
}