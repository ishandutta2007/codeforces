#include <bits/stdc++.h>

using namespace std;

const int LOGN = 20;
const int MAXN = 1E6;

struct RangeMinimumQuery 
{
	long long vecmin[LOGN][MAXN];
	
	void build(const vector<long long> &v)
	{
		copy(v.begin(), v.end(), vecmin[0]);
		for (int i = 1; i < LOGN; i++)
		{
			for (int j = 0; j < MAXN; j++)
			{
				vecmin[i][j] = vecmin[i - 1][j];
				int k = j + (1 << (i - 1));
				if (k < MAXN)
					vecmin[i][j] = min(vecmin[i][j], vecmin[i - 1][k]);
			}
		}
	}
	
	long long query_min(int l, int r)
	{
		int len = r - l + 1;
		int ind = 31 - __builtin_clz(len);
		return min(vecmin[ind][l], vecmin[ind][r - (1 << ind) + 1]);
	}
};

const long long INF = 1E18 + 5;
long long a[MAXN];
int freq[70];
RangeMinimumQuery rmq;

long long solve(int l, int r)
{
	//cout << "solve " << l << " " << r << endl;
	if (l == r)
		return 1;
	int mid = (l + r) / 2;
	long long ans = 0;
	int rightPtr = mid;
	int samePtr = mid;
	fill(freq, freq + 70, 0);
	long long leftMax = a[mid];
	for (int i = mid; i >= l; i--)
	{
		leftMax = max(leftMax, a[i]);
		while (rightPtr + 1 <= r && a[rightPtr + 1] <= leftMax)
		{
			freq[__builtin_popcountll(rmq.query_min(mid, rightPtr + 1))]++;
			rightPtr++;
		}
		long long leftMin = rmq.query_min(i, mid);
		if (samePtr > mid)
		{
			freq[__builtin_popcountll(rmq.query_min(i + 1, mid))] -= samePtr - mid;
			freq[__builtin_popcountll(rmq.query_min(i, mid))] += samePtr - mid;
		}
		while (samePtr + 1 <= rightPtr && samePtr + 1 <= r && a[samePtr + 1] > leftMin)
		{
			freq[__builtin_popcountll(rmq.query_min(mid, samePtr + 1))]--;
			freq[__builtin_popcountll(rmq.query_min(i, samePtr + 1))]++;
			samePtr++;
		}
		ans += freq[__builtin_popcountll(leftMax)];
		//cout << "anchor " << i << " " << freq[__builtin_popcountll(leftMax)] << endl;
		//cout << "rightptr " << rightPtr << endl;
		//for (int j = 0; j <= 4; j++)
			//cout << freq[j] << " ";
		//cout << endl;
		//cout << "at " << i << " max is " << leftMax << endl;
		//cout << "at " << i << " " << __builtin_popcountll(leftMax) << " added " << freq[__builtin_popcountll(leftMax)] << endl;
	}
	fill(freq, freq + 70, 0);
	int leftPtr = mid + 1;
	samePtr = mid + 1;
	long long rightMax = a[mid + 1];
	for (int i = mid + 1; i <= r; i++)
	{
		rightMax = max(rightMax, a[i]);
		while (leftPtr - 1 >= l && a[leftPtr - 1] < rightMax)
		{
			freq[__builtin_popcountll(rmq.query_min(leftPtr - 1, mid))]++;
			leftPtr--;
		}
		long long rightMin = rmq.query_min(mid + 1, i);
		if (samePtr <= mid)
		{
			freq[__builtin_popcountll(rmq.query_min(mid, i - 1))] -= mid - samePtr + 1;
			freq[__builtin_popcountll(rmq.query_min(mid, i))] += mid - samePtr + 1;
		}
		while (samePtr - 1 >= leftPtr && samePtr - 1 >= l && a[samePtr - 1] > rightMin)
		{
			freq[__builtin_popcountll(rmq.query_min(samePtr - 1, mid))]--;
			freq[__builtin_popcountll(rmq.query_min(samePtr - 1, i))]++;
			samePtr--;
		}
		ans += freq[__builtin_popcountll(rightMax)];
		//cout << "anchor " << i << " " << freq[__builtin_popcountll(rightMax)] << endl;
		//cout << "at " << i << " max is " << leftMax << endl;
		//cout << "at " << i << " " << __builtin_popcountll(leftMax) << " added " << freq[__builtin_popcountll(leftMax)] << endl;
	}
	//cout << "cont " << l << " " << r << " " << ans << endl;
	ans += solve(l, mid);
	ans += solve(mid + 1, r);
	return ans;
}

long long solve_brute(int n)
{
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		long long mx = a[i];
		long long mn = a[i];
		for (int j = i; j < n; j++)
		{
			mx = max(mx, a[j]);
			mn = min(mn, a[j]);
			if (__builtin_popcountll(mx) == __builtin_popcountll(mn))
				ans++;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		vec.push_back(a[i]);
	}
	rmq.build(vec);
	cout << solve(0, n - 1) << "\n";
	//cout << solve_brute(n) << "\n";
	return 0;
}