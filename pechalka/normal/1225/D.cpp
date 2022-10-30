#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>
#include <string>
#include <map>

using namespace std;

int k;

void toPrime(int x, vector<int> &res, vector<int> &pows){
	int i = 2;
	while (i * i <= x){
		if (x % i == 0){
			int curpow = 0;
			while (x % i == 0) {
				x /= i;
				++curpow;
			}
			if (curpow % k != 0){
				res.emplace_back(i);
				pows.emplace_back(curpow);
			}
		}
		++i;
	}
	if (x > 1){
		res.emplace_back(x);
		pows.emplace_back(1);
	}
}

int main(){
	int n;
	cin >> n >> k;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	vector<vector<int>> primals(n);
	vector<vector<int>> pows(n);
	for (int i = 0; i < n; ++i){
		toPrime(A[i], primals[i], pows[i]);
	}
	vector<int> order(n);
	for (int i = 0; i < n; ++i)
		order[i] = i;
	stable_sort(order.begin(), order.end(), [&primals](int a, int b){
		return primals[a] < primals[b];
		});
	int first = 0;
	long long ans = 0;
	for (;first < n;){
		int last = first;
		while (last < n - 1 && primals[order[last + 1]] == primals[order[last]])
			++last;
		map<long long, long long> cnt;
		map<long long, long long> hash2;
		for (int j = first; j <= last; ++j){
			int i = order[j];
			long long thisHash = 0;
			long long thisHash2 = 0;
			for (int x : pows[i])
				thisHash = thisHash * k + x % k;
			for (int x : pows[i])
				thisHash2 = thisHash2 * k + k - x % k;
			if (cnt.count(thisHash) == 0)
				cnt[thisHash] = 1;
			else
				++cnt[thisHash];
			hash2[thisHash] = thisHash2;
		}
		for (auto t : cnt){
			if (hash2[t.first] == t.first)
				ans += t.second * (t.second - 1);
			else if (cnt.count(hash2[t.first]))
				ans += t.second * cnt[hash2[t.first]];
		}
		first = last + 1;
	}
	cout << ans / 2;
	return 0;
}