#include <iostream>
#include <string>
using namespace std;
int isVowel(char c)
{
	if((c=='a')||(c=='o')||(c=='y')||(c=='e')||(c=='u')||(c=='i')||(c=='A')||(c=='O')||(c=='Y')||(c=='E')||(c=='U')||(c=='I')) return 1;
	return 0;
}
char lower(char c)
{
	return c+32;
}
int main()
{
	char ch;
	int i;
	string s;
	cin >> s;
	for(i=0;i<s.size();i++)
	{
		ch = s[i];
		if(isVowel(ch)) continue;
		cout << '.';
		if(ch<=90) cout << lower(ch);
		else cout << ch;
	}
	cout << endl;	
}