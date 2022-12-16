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
char C[1000000];
int Tot;
int Typ[500];
int Cur[500];

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	cin >> C;
	for (int i = 0; i < N; i++)
		if (Typ[C[i]] == 0)
		{
			Typ[C[i]] = 1;
			Tot++;
		}
	int l = 0, r = 0;
	while (Tot > 0)
	{
		if (Cur[C[r]] == 0)
			Tot--;
		Cur[C[r]]++;
		r++;
	}
	int ans = r - l;
	for (l = 1; l < N; l++)
	{
		Cur[C[l - 1]]--;
		if (Cur[C[l - 1]] == 0)
		{
			while (r < N && C[r] != C[l - 1])
			{
				Cur[C[r]]++;
				r++;
			}
			if (r >= N) break;
			Cur[C[r]]++;
			r++;
		}
//		cout << l << " " << r << endl;
		if (ans > r - l) ans = r - l;
	}
	cout << ans << endl;
	return 0;
}