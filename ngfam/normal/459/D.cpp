#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m, a[N], cnt[N], curr[N];	

vector < int > values;
map < int, int > idx;

struct fenwick{
	int bit[N];

	void upd(int i, int val){
		for(; i < N; i += i & -i){
			bit[i] += val;	
		}	
	}
	
	int ask(int i){
		int result = 0;
		for(; i > 0; i &= i - 1){
			result += bit[i];
		}
		return result;
	}
}fwt;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		values.push_back(a[i]);
	}

	sort(values.begin(), values.end());
	unique(values.begin(), values.end());

	for(int i = 0; i < values.size(); ++i){
		idx[values[i]] = i + 1;
	}

	for(int i = 1; i <= n; ++i){
		a[i] = idx[a[i]];
		++cnt[a[i]];
	}

	long long ans = 0;

	for(int i = n; i >= 1; --i){
		ans += fwt.ask(cnt[a[i]] - 1);
		--cnt[a[i]];
		++curr[a[i]];
		fwt.upd(curr[a[i]], 1);	
	}

	cout << ans;

	return 0;
}