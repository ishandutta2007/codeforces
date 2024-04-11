#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[200002], d[200002], before, after;
vector<int> locs;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
			locs.push_back(i);
	}
	int curr = 0;
	before = -200002, after = locs[0];
	for (int i = 0; i < locs.size(); i++)
	{
		for (; curr <= locs[i]; curr++)
			d[curr] = after - curr <= curr - before ? after - curr : curr - before;
		before = locs[i], after = i == locs.size() - 1 ? 200002 : locs[i + 1];
	}
	for (; curr < n; curr++)
		d[curr] = curr - before;
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
	cout << endl;
}