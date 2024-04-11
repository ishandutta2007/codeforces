#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
int a[maxn], cnt[maxn], n, k;
vector<int> all;
set<pie> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < k - 1; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		s.erase(MP(cnt[id], -a[i]));
		cnt[id]++;
		s.insert(MP(cnt[id], -a[i]));
	}
	for(int i = k - 1; i < n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		s.erase(MP(cnt[id], -a[i]));
		cnt[id]++;
		s.insert(MP(cnt[id], -a[i]));
		if(i >= k){
			id = lower_bound(all.begin(), all.end(), a[i - k]) - all.begin();
			s.erase(MP(cnt[id], -a[i - k]));
			cnt[id]--;
			if(cnt[id])
				s.insert(MP(cnt[id], -a[i - k]));
		}
		auto x = *s.begin();
		if(x.L == 1)
			cout << -x.R << '\n';
		else
			cout << "Nothing\n";
	}
	return 0;
}