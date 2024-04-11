#include<iostream>
#include<string>
using namespace std;



int main()
{
	string s = "", res = "";
	int b = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'h' and res == "")
		{
			res += s[i];
		}
		if (s[i] == 'e' and res == "h")
		{
			res += s[i];
		}
		if (s[i] == 'l' and (res == "he" or res == "hel"))
		{
			res += s[i];
		}
		if (s[i] == 'o' and res == "hell")
		{
			res += s[i];
		}
		b += 1;
	}
	if (res == "hello" &&b==5)
	{
		cout << "YES";
	}
	else {
		if (res == "hello") {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
}