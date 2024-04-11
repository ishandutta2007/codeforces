//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		if (i % 2 == 0)
			cout << "I love that ";
		else
			cout << "I hate that ";
	}
	if (N % 2 == 0)
		cout << "I love it" << endl;
	else
		cout << "I hate it" << endl;
	return 0;
}