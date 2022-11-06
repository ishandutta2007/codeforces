#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<int> lastseen(1000001, -1);
	int x, y;
	int minpos;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		minpos = i-y;
		int count = 0;
		for (int j = 1; j*j <= x; ++j)
		{
			if (x % j == 0)
			{
				if (lastseen[j] < minpos) {
					count ++;
					lastseen[j] = i;
				}
				else {
					lastseen[j] = i;
				}
				if (lastseen[x/j] < minpos) {
					count++;
				} else {
					lastseen[x/j] = i;
				}
				lastseen[j] = i;
				lastseen[x/j] = i;
			}
		}
		cout << count << "\n";
	}
}