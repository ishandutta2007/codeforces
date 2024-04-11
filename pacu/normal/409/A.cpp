#include <iostream>
#include <string>
using namespace std;

string s,t;

int main()
{
	cin >> s >> t;
	int d = 0;
	for(int i=0;i<s.size();i+=2)
	{
		if(s[i]==t[i]) continue;
		else if(s[i]=='8' && t[i]=='(') d--;
		else if(s[i]=='8') d++;
		else if(s[i]=='(' && t[i]=='[') d--;
		else if(s[i]=='(') d++;
		else if(s[i]=='[' && t[i]=='8') d--;
		else d++;
	}
	if(d==0) cout << "TIE\n";
	else if(d>0) cout << "TEAM 1 WINS\n";
	else cout << "TEAM 2 WINS\n";
}