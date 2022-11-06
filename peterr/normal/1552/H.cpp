#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
const int LOGN = 8;
int queries[LOGN + 1];

int query(int mult)
{
	//int x1 = 20;
	//int y1 = 1;
	//int x2 = 50;
	//int y2 = 129;
	//int ans = 0;
	vector<pair<int, int>> vec;
	for (int i = mult; i <= MAXN; i += mult)
	{
		for (int j = 1; j <= MAXN; j++)
		{
			vec.push_back({j, i});
			//if (j >= x1 && j <= x2 && i >= y1 && i <= y2)
				//ans++;
		}
	} 
	//return ans;
	cout << "? " << vec.size() << endl;
	for (pair<int, int> pr : vec)
	{
		cout << pr.first << " " << pr.second << " ";
	}
	cout << endl;
	int q;
	cin >> q;
	return q;
}

int main()
{
	int total = query(1);
	queries[0] = total;
	int lo = 1;
	int hi = 7;
	for (int i = 0; i < 3; i++)
	{
		int mid = (lo + hi) / 2;
		//cout << "mid " << mid << endl;
		int q = query(1 << mid);
		queries[mid] = q;
		if (q * (1 << mid) == total)
			lo = mid + 1;
		else
			hi = mid;
	}
	//cout << "total " << total << endl;
	//cout << "lo " << lo << endl;
	//cout << "queries[lo] " << queries[lo] << endl;
	//cout << "queries[lo - 1] " << queries[lo - 1] << endl;
	int w = abs(queries[lo - 1] - 2 * queries[lo]) - 1;
	int h = total / (w + 1) - 1;
	//cout << "width " << w << endl;
	//cout << "height " << h << endl;
	cout << "! " << 2 * (w + h) << endl;
	return 0;
}