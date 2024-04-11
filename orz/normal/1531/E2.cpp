#define sz(x) (static_cast<int>((x).size()))
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
void try_calculating(const vb& v, int& pointer, const int l, const int r, const int g, vi& numbers)
{
	if (r - l == 1)
		return;
	if (pointer >= sz(v))
	{
		++pointer;
		return;
	}
	int m = (l + r) / 2;
	int left_side = m - l, right_side = r - m;
	try_calculating(v, pointer, l, m, 2 * g + 1, numbers);
	try_calculating(v, pointer, m, r, 2 * g + 2, numbers);
	if (sz(numbers) <= g)
		numbers.resize(g + 1);
	numbers[g] = pointer;
	int i = l, j = m, k = l;
	while (i < m && j < r)
	{
		if (pointer >= sz(v))
		{
			++pointer;
			return;
		}
		else if (v[pointer])
			++j;
		else
			++i;
		++k;
		++pointer;
	}

}
void try_constructing(const vb& v, int& pointer, const int l, const int r, vi& ans, vi& temp, const int g, const vi& numbers)
{
	if (r - l == 1)
		return;
	if (pointer >= sz(v))
	{
		++pointer;
		return;
	}
	int m = (l + r) / 2;
	int left_side = m - l, right_side = r - m;
	int old_pointer = pointer;
	pointer = numbers[g];
	int i = l, j = m, k = l;
	while (i < m && j < r)
	{
		if (pointer >= sz(v))
		{
			++pointer;
			return;
		}
		else if (v[pointer])
			temp[j++] = ans[k++];
		else
			temp[i++] = ans[k++];
		++pointer;
	}
	while (i < m)
		temp[i++] = ans[k++];
	while (j < r)
		temp[j++] = ans[k++];
	for (i = l; i < r; ++i)
		ans[i] = temp[i];
	try_constructing(v, old_pointer, l, m, ans, temp, 2 * g + 1, numbers);
	try_constructing(v, old_pointer, m, r, ans, temp, 2 * g + 2, numbers);
}
int compare(const int x, const int y)
{
	if (x < y)
		return -1;
	else
		return x > y;
}
int find_verdict(const vb& v, const int n, vi& ans, vi& temp)
{
	ans.resize(n);
	temp.resize(n);
	for (int i = 0; i < n; ++i)
		ans[i] = i + 1;
	int pointer = 0;
	vi calculated;
	try_calculating(v, pointer, 0, n, 0, calculated);
	int compared = compare(pointer, sz(v));
	if (compared == 0)
	{
		for (int i = 0; i < n; ++i)
			ans[i] = i + 1;
		pointer = 0;
		try_constructing(v, pointer, 0, n, ans, temp, 0, calculated);
	}
	return compared;
}
int main()
{
#ifdef ONPC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	vb v(sz(s));
	for (int i = 0; i < sz(s); ++i)
		v[i] = s[i] == '1';
	int x = 1;
	int y = min(100001, sz(s) + 2);
	int z = (y - x) >> 1;
	vi ans;
	vi temp;
	while (true)
	{
		z += x;
		int verdict = find_verdict(v, z, ans, temp);
		if (verdict == 1)
			y = z;
		else if (verdict == -1)
			x = z + 1;
		else
		{
			x = z;
			y = z + 1;
			break;
		}
		z = (y - x) >> 1;
	}
	cout << sz(ans) << '\n';
	for (int i = 0; i < sz(ans); ++i)
		cout << ans[i] << " \n"[i == sz(ans) - 1];
}