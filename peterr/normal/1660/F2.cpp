#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
const int BIAS = MAXN;
string s;
int freq1[3 * MAXN];
int freq2[3 * MAXN];

long long solve(int lo, int hi)
{
	if (lo >= hi)
		return 0;
	int mid = (lo + hi) / 2;
	long long ans = solve(lo, mid) + solve(mid + 1, hi);
	int n = hi - lo + 1;
	fill(freq1 + BIAS - n, freq1 + BIAS + n + 1, 0);
	fill(freq2 + BIAS - n, freq2 + BIAS + n + 1, 0);
	int bal = 0;
	for (int i = mid; i >= lo; i--)
	{
		if (s[i] == '+')
			bal++;
		else
			bal--;
		freq1[bal + BIAS]++;
	}
	bal = 0;
	for (int i = mid + 1; i <= hi; i++)
	{
		if (s[i] == '+')
			bal++;
		else
			bal--;
		freq2[bal + BIAS]++;
	}
	queue<int> q;
	q.push(0);
	q.push(0);
	q.push(0);
	for (int i = n; i >= -n; i--)
	{
		int num = q.front() + freq2[-i + BIAS];
		q.pop();
		ans += (long long) freq1[i + BIAS] * num;
		q.push(num);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n >> s;
		cout << solve(0, n - 1) << "\n";
	}
	return 0;
}