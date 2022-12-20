#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char c;
	string s;
	cin >> c >> s;
	for(int i=0;i<s.size();i++)
	{
		int j;
		for(j=0;j<A.size();j++)
			if(A[j]==s[i])
				break;
		if(c=='R')
			s[i] = A[j-1];
		else
			s[i] = A[j+1];
	}
	cout << s << endl;
}