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

typedef long long llong;

using namespace std;

llong C[200000];
llong ID[200000];
bool IC[200000];

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	llong N, M;
	llong s = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> C[i];
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> ID[i];
		IC[ID[i]] = true;
	}
	llong ans = 0;
	s = 0;
	llong sc = 0;
	for (int i = 1; i <= N; i++)
	{
		if (IC[i])
			ans += C[i] * s;
		else
			ans += C[i] * C[i % N + 1] + (IC[i % N + 1] ? sc - C[i % N + 1] : sc) * C[i];
		s += C[i];
		if (IC[i]) sc += C[i];
	}
//	cout << ans << endl;
	cout << ans << endl;
	return 0;
}