#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	int N;
	cin >> N >> s;
	for(int i=0;i<N;i++)
	{
		for(int d=1;d<N;d++)
		{
			if((i+4*d)>=N)
				break;
			if((s[i]=='*')&&(s[i+d]=='*')&&(s[i+2*d]=='*')&&(s[i+3*d]=='*')&&(s[i+4*d]=='*'))
			{
				cout << "yes\n";
				return 0;
			}
		}
	}
	cout << "no\n";
	return 0;
}