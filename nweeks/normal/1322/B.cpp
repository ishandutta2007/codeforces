#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 4e5;

int arr[MAXN];
int reduced[MAXN];

int n;

int calc_ans(int p)
{
	int mod = 1<<(p+1);

	for (int i(0); i < n; ++i)
		reduced[i] = arr[i] % mod;

	sort(reduced, reduced + n);

	// bit p on if >= mod/2

	int lower = mod/2;
	int upper = mod-1;
	int ans(0);
	for (int i(0); i < n-1; ++i)
	{
		int l(i+1), r(n-1);

		while (l < r)
		{
			int m = (l+r)/2;
			if (reduced[i] + reduced[m] < lower)
				l = m+1;
			else
				r = m;
		}

		int lft=l;
		l = i+1, r=n-1;
		while (l < r)
		{
			int m = (l+r+1)/2;
			if (reduced[i] +reduced[m] > upper)
				r=m-1;
			else
				l = m;
		}
		int rgt = l;
		if (lft <= rgt and lower <= reduced[i]+reduced[lft] 
				and reduced[i] + reduced[rgt] <= upper)
			ans ^= (rgt-lft+1)%2;

		l = i+1, r = n-1;
		while (l < r)
		{
			int m = (l+r)/2;
			if (reduced[i] + reduced[m] < mod + lower)
				l = m+1;
			else
				r = m;
		}
		lft = l;
		l = i+1, r=n-1;
		while (l < r)
		{
			int m = (l+r+1)/2;
			if (reduced[i] + reduced[m] > upper + mod)
				r = m-1;
			else
				l = m;
		}
		rgt = l;
		if (lft <= rgt and lower+mod <= reduced[i]+reduced[lft]
			and upper+mod >= reduced[i] + reduced[rgt])
			ans ^= (rgt-lft+1)%2;
	}
	return ans * lower;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> arr[i];
	int ans(0);
	for (int p(0); p < 30; ++p)
		ans += calc_ans(p);
	cout << ans << endl;
}