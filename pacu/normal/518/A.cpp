#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s,t;
	cin >> s >> t;
	int N = s.size();
	bool carry = 1;
	for(int i=(N-1);i>=0;i--)
	{
		if(!carry)
			break;
		if(s[i]=='z')
		{
			for(int j=i;j<N;j++)
				s[j] = 'a';
		}
		else
		{
			s[i] = (char)(s[i]+1);
			carry = 0;
		}
	}
	if(s<t) cout << s << endl;
	else cout << "No such string" << endl;
	return 0;
}