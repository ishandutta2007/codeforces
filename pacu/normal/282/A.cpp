#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int x = 0;
	int N;
	cin >> N;
	while(cin >> s)
	{
		if((s[0]=='+')||(s[2]=='+')) x++;
		else x--;
	}
	cout << x << endl;
}