#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int levels = 0;
	int cur = 1;
	int dif = 1;
	while(N >= cur)
	{
		N -= cur;
		levels++;
		dif++;
		cur += dif;
	}
	cout << levels << endl;
}