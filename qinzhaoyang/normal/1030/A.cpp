#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool ans = false , input;
	for(int i = 1; i <= n; i++)
	{
		cin >> input;
		ans = ans | input;
	}
	if(ans)
		cout << "HARD" << endl;
	else
		cout << "EASY" << endl;
	return 0;
}