#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40;
const int MAXK = 10;
long long a[MAXK];
vector<int> b[MAXK];
int n, k;

void solve(long long active, long long num, int ind, vector<long long> &newStates)
{
	long long match = active & a[ind];
	long long numMatch = __builtin_popcountll(match);
	long long ones = __builtin_popcountll(num & match);
	long long zeros = numMatch - ones;
	long long extra = __builtin_popcountll(a[ind]) - ones - zeros;
	long long newNum = num & (~match);
	//cout << "newactive " << newActive << endl;
	//cout << "numMatch " << numMatch << endl;
	//cout << "ones " << ones << endl;
	//cout << "zeros " << zeros << endl;
	//cout << "extra " << extra << endl;
	if (ones)
	{
		long long mask = (1LL << b[ind][(int) b[ind].size() - ones]) - 1;
		mask = ~mask;
		newNum = newNum | (mask & a[ind]);
	}
	//cout << "newnum " << bitset<10>(newNum) << endl;
	newStates.push_back(newNum);
	for (int i = 0; i < extra; i++)
	{
		newNum = newNum | (1LL << b[ind][(int) b[ind].size() - i - ones - 1]);
		newStates.push_back(newNum);
	}
}

int main()
{
	cin >> n >> k;
	long long totalBits = 0;
	for (int i = 0; i < k; i++)
	{
		int len;
		cin >> len;
		for (int j = 0; j < len; j++)
		{
			int x;
			cin >> x;
			x--;
			a[i] = a[i] | (1LL << x);
			b[i].push_back(x);
		}
		totalBits = totalBits | a[i];
		//cout << "a of " << i << " = " << a[i] << endl;
	}
	if (n == 1)
	{
		cout << "ACCEPTED\n";
		return 0;
	}
	if (__builtin_popcountll(totalBits) < n)
	{
		cout << "REJECTED\n";
		return 0;
	}
	long long maskExceptLast = 0;
	for (int i = 0; i < k - 1; i++)
	{
		maskExceptLast = maskExceptLast | a[i];
	}
	if (__builtin_popcountll(maskExceptLast) < n && __builtin_popcountll(a[k - 1]) < n)
	{
		cout << "REJECTED\n";
		return 0;
	}
	long long active = 0;
	vector<long long> states;
	states.push_back(0);
	for (int i = 0; i < k; i++)
	{
		//cout << "iteration " << i << endl;
		vector<long long> newStates;
		for (long long x : states)
		{
			//cout << "solve " << bitset<10>(pr.second) << " " << i << endl;
			solve(active, x, i, newStates);
		}
		swap(states, newStates);
		active = active | a[i];
		//cout << "\tsize " << states.size() << endl;
	}
	bool good = true;
	for (long long x : states)
	{
		//cout << bitset<10>(pr.second) << endl;
		long long mask = (1LL << n) - 1;
		if (__builtin_popcountll((mask & (~x)) + 1) != 1)
		{
			good = false;
			break;
		}
	}
	cout << (good ? "ACCEPTED" : "REJECTED") << "\n";
	return 0;
}