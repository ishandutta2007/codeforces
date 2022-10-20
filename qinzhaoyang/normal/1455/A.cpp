#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); 
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << s.size() << endl;
	}
	return 0;
}