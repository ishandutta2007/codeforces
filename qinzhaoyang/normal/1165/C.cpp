#include <iostream>
#include <string>

using namespace std;

string s;
int n;
string res;

int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		if(res.size() % 2 == 0 || res[res.size() - 1] != s[i])
			res += s[i];
	if(res.size() % 2 == 1)
		res.erase(res.end() - 1);
	cout << n - int(res.size()) << endl << res << endl;
	return 0;
}