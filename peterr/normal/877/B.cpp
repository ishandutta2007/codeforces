#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int prefa[MAXN + 2];
int prefb[MAXN + 2];

int query(int arr[MAXN + 2], int l, int r)
{
	if (l > r)
		return 0;
	//cout << "testing " << l << " " << r << endl;
	//assert(arr[r] >= arr[l - 1]);
	return arr[r] - arr[l - 1];
}

int main()
{
	string s;
	cin >> s;
	s = "#" + s;
	for (int i = 1; i < (int) s.length(); i++)
	{
		prefa[i] = prefa[i - 1] + (s[i] == 'a');
		prefb[i] = prefb[i - 1] + (s[i] == 'b');
		//cout << "arr " << i << " " << prefa[i] << endl;
		//cout << "arr " << i << " " << prefb[i] << endl;
	}
	prefa[s.length()] = prefa[s.length() - 1];
	prefb[s.length()] = prefb[s.length() - 1];
	int ans = 0;
	for (int i = 0; i < (int) s.length(); i++)
	{
		for (int j = i + 1; j <= (int) s.length(); j++)
		{
			ans = max(ans, query(prefa, 1, i) + query(prefa, j, s.length()) + query(prefb, i + 1, j - 1));
		}
	}
	cout << ans << "\n";
	return 0;
}