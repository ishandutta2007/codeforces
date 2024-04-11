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

long long N;

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	long long s = 0;
	for (long long i = 1; i <= N; i++)
	{
		long long a;
		cin >> a;
		s += a;
		s %= 2;
		cout << 2 - (s + i) % 2 << endl;
	}
	return 0;
}