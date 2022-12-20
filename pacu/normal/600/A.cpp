#include <iostream>
#include <string>
using namespace std;

string s;

string a,b;

bool isend(int j)
{
	return (j==s.size())||(s[j]==',')||(s[j]==';');
}

int main()
{
	cin >> s;
	int start = 0;
	int kA = 0;
	int kB = 0;
	while(start < s.size())
	{
		int i = start;
		bool good = !isend(i);
		string tmp;
		while(!isend(i))
		{
			tmp += s[i];
			if(s[i] < 48 || s[i] > 57)
				good = 0;
			if(s[i]=='0' && i==start && !isend(i+1))
				good = 0;
			i++;
		}
		if(good)
		{
			if(kA>0) a += ',';
			a += tmp;
			kA++;
		}
		else
		{
			if(kB>0) b += ',';
			b += tmp;
			kB++;
		}
		start = i+1;
	}
	if(kB>0)
	{
		if(isend(s.size()-1)) kB++,b += ',';
	}
	else
		if(isend(s.size()-1)) kB++;
	if(kA==0) cout << "-\n";
	else cout << "\"" << a << "\"" << '\n';
	if(kB==0) cout << "-\n";
	else cout << "\"" << b << "\"" << '\n';
}