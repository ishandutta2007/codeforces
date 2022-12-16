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

int N, K;
double L, V1, V2;

bool Valid (int n, double l, double t)
{
	if (t * V1 + 1E-6 > l) return true;
	if (n <= K)
		return (l < t * V2 + 1E-6);
	double ts = (l - V1 * t) / (V2 - V1);
	double tb = (l - V1 * t) / (V2 + V1);
	return Valid (n - K, l - (ts + tb) * V1, t - ts - tb);
}

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N >> L >> V1 >> V2 >> K;
	double l = L / V2, r = L / V1;
	for (int i = 0; i < 1000; i++)
	{
		double m = (l + r) / 2;
	//	cout << N << " " << L << " " << m << endl;
		if (Valid (N, L, m))
			r = m;
		else
			l = m;
	}
	cout << fixed << setprecision (10) << (l + r) / 2 << endl;
	return 0;
}