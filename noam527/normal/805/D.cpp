#include <iostream>
#include <string>
#define md ((int)1e9 + 7);
using namespace std;

string s;
int sum = 0, cnt = 0;

int main()
{
	cin >> s;
	
	int j = s.size() - 1;
	while (j >= 0 && s[j] == 'a')
		j--;
	for (int i = j; i >= 0; i--)
	{
		if (s[i] == 'a')
		{
			sum = (sum + cnt) % md;
			cnt = (cnt * 2) % md;
			//cout << "sum: " << sum << endl;
		}
		else
			cnt++;
	}
	cout << sum << endl;
	
}