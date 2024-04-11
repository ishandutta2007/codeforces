#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

vector<int> calc_lis(vector<int> &arr)
{
	int n = SZ(arr);
	vector<int> cur_lis;
	vector<int> ans(n);
	ans[0] = 1;
	cur_lis.push_back(arr[0]);
	for (int i(1); i < n; ++i)
	{
		if (cur_lis[0] > arr[i])
		{
			cur_lis[0] = arr[i];
			ans[i] = 1;
			continue;
		}
		int l(0), r(SZ(cur_lis)-1);
		while (l < r)
		{
			int m = (l+r+1)/2;
			if (cur_lis[m] <= arr[i])
				l=m;
			else
				r = m-1;
		}
		if (l == SZ(cur_lis)-1)
			cur_lis.push_back(arr[i]);
		else
			cur_lis[l+1]=arr[i];
		ans[i] = l+2;
	}
	return ans;
}

void solve(void)
{
	int nb_segments, len_lin;
	cin >> nb_segments >> len_lin;

	vector<int> cnt(len_lin+1);
	for (int i(0); i < nb_segments; ++i)
	{
		int l, r;
		cin >> l >> r;
		cnt[l-1]++;
		cnt[r]--;
	}
	for (int i(0); i < len_lin; ++i)
		cnt[i+1] += cnt[i];
	
	cnt.pop_back();
	auto pref = calc_lis(cnt);
	reverse(cnt.begin(), cnt.end());
	auto suff = calc_lis(cnt);
	reverse(suff.begin(), suff.end());
	int ans(0);
	for (int i(0); i < len_lin; ++i)
		ans = max(pref[i]+suff[i]-1, ans);
	cout<<ans<<endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int __t(1);
	while (__t--)
		solve();
}