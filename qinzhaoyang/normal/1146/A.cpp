#include <iostream>

using namespace std;

string a;
int cnt = 0;

int main()
{
	cin >> a;
	for(int i = 0; i < a.size(); i++)
		if(a[i] == 'a')
			cnt++;
	if(2 * cnt > a.size())
		cout << a.size() << endl;
	else
		cout << 2 * cnt - 1 << endl;
	return 0;
}