#include <iostream>
#include <string>
using namespace std;

void out(int k)
{
	for(int i=0;i<2*k;i++)
		cout << " ";
}

int main()
{
	string s;
	cin >> s;
	int depth = 0;
	for(int i=0;i<s.size();)
	{
		if(s[i+1]=='/')
		{
			out(--depth);
			cout << "</" << s[i+2] << ">" << endl;
			i += 4;
		}
		else
		{
			out(depth++);
			cout << "<" << s[i+1] << ">" << endl;
			i += 3;
		}
	}
}