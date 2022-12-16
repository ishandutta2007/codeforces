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

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int N, A = 0, B = 0;
	cin >> N;
	for (int t = 0; t < N; t++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) A++;
		if (a < b) B++;
	}
	if (A > B)
		cout << "Mishka" << endl;
	if (A == B)
		cout << "Friendship is magic!^^" << endl;
	if (A < B)
		cout << "Chris" << endl;
	return 0;
}