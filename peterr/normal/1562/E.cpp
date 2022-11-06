#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, int> p;
	vector<p> res;
	rep(i,0,sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

const int MAXN = 5000;
int mp[MAXN * MAXN];
vector<int> rev;
int dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		SuffixArray suf(s);
		RMQ<int> rmq(suf.lcp);
		rev = vector<int>(suf.sa.size());
		for (int i = 1; i < (int) suf.sa.size(); i++)
		{
			rev[suf.sa[i]] = i;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			dp[i] = n - i;
			for (int j = 0; j < i; j++)
			{
				if (s[j] > s[i])
					continue;
				if (s[j] < s[i])
					dp[i] = max(dp[i], dp[j] + n - i);
				else
				{
					int ind1 = min(rev[i], rev[j]);
					int ind2 = max(rev[i], rev[j]);
					int pref = rmq.query(ind1 + 1, ind2 + 1);
					if (pref == n - i || s[i + pref] < s[j + pref])
						continue;
					dp[i] = max(dp[i], dp[j] + n - i - pref);
					
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
		
		//vector<pair<int, int>> vec;
		//for (int i = 0; i < n; i++)
		//{
			//for (int j = i; j < n; j++)
			//{
				//vec.push_back({i, j});
			//}
		//}
		////cout << "sa" << endl;
		////for (int i = 0; i < (int) suf.sa.size(); i++)
		////{
			////cout << i << " " << suf.sa[i] << endl;
		////}
		////cout << "lcp" << endl;
		////for (int i = 0; i < (int) suf.lcp.size(); i++)
		////{
			////cout << i << " " << suf.lcp[i] << endl;
		////}
		//sort(vec.begin(), vec.end(), [&] (pair<int, int> x, pair<int, int> y) {
			//if (x.first == y.first)
				//return x.second < y.second;
			//int ind1 = rev[x.first];
			//int ind2 = rev[y.first];
			//int pref = rmq.query(min(ind1, ind2) + 1, max(ind1, ind2) + 1);
			//int len1 = x.second - x.first + 1;
			//int len2 = y.second - y.first + 1;
			//if (ind1 < ind2)
			//{
				//if (len2 > pref)
					//return true;
			//}
			//else
			//{
				//if (len1 > pref)
					//return false;
			//}
			//return len1 < len2;
		//});
		////cout << "sorted " << endl;
		////for (pair<int, int> pr : vec)
			////cout << pr.first << " " << pr.second << endl;
		//int cnt = 0;
		//int ptr = 0;
		//while (ptr < (int) vec.size())
		//{
			//pair<int, int> pr1 = vec[ptr];
			//int len1 = pr1.second - pr1.first + 1;
			//int ind1 = rev[pr1.first];
			//while (ptr < (int) vec.size())
			//{
				//pair<int, int> pr2 = vec[ptr];
				//int len2 = pr2.second - pr2.first + 1;
				//int ind2 = rev[pr2.first];
				//if (len1 != len2)
					//break;
				//if (pr1 != pr2 && rmq.query(min(ind1, ind2) + 1, max(ind1, ind2) + 1) < len1)
					//break;
				//mp[pr2.first * MAXN + pr2.second] = cnt;
				//ptr++;
			//}
			//cnt++;
		//}
		//vector<int> nums;
		//for (int i = 0; i < n; i++)
		//{
			//for (int j = i; j < n; j++)
			//{
				//int num = mp[i * MAXN + j];
				//nums.push_back(num);
			//}
		//}
		//vector<int> ans = lis(nums);
		//cout << ans.size() << "\n";
	}
	return 0;
}