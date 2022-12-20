#include <iostream>
#include <string>
using namespace std;

string s,t;

int main()
{
	cin >> s >> t;
	int N = s.size();
	string p = "";
	int d = 0;
	for(int i=0;i<N;i++)
	{
		if(s[i]==t[i])
			p += '0';
		else if(d>0)
		{
			p += s[i];
			d--;
		}
		else
		{
			p += t[i];
			d++;
		}
	}
	if(d)
		cout << "impossible\n";
	else
		cout << p << "\n";
	return 0;
}