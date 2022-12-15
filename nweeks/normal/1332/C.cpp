#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int solve(void)
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	int word_size = k;
	int cnt_words = n/k;
	vector<string> parts(cnt_words);
	for (int i(0); i < cnt_words; ++i)
		for (int j(0); j < word_size; ++j)
			parts[i] += s[i*word_size + j];
	
	int ans(0);
	for (int i(0); i <= word_size-1-i; ++i)
	{
		int cur_ans(1e9);
		for (char c('a'); c <= 'z' ; ++c)
		{
			int tmp(0);
			for (int j(0); j < cnt_words; ++j)
			{
				if (parts[j][i]!= c)
					++tmp;
				if (word_size - 1 - i != i and parts[j][word_size - 1 - i] != c)
					++tmp;
			}
			cur_ans = min(cur_ans, tmp);
		}
		ans += cur_ans;
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}