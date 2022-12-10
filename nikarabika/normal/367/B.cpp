#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 2e5 + 10;
int cnt[maxn], cnt2[maxn], po[maxn];
vector<int> all, ans;
int a[maxn], b[maxn];
int n, m, p;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++){
		cin >> b[i];
		all.PB(b[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < m; i++){
		int id = lower_bound(all.begin(), all.end(), b[i]) - all.begin();
		cnt[id]++;
	}
	for(int i = 0; i < n; i++){
		vector<int>::iterator it = lower_bound(all.begin(), all.end(), a[i]);
		if(it == all.end() or (*it) != a[i])
			po[i] = -1;
		else
			po[i] = it - all.begin();
	}
	for(int q = 0; q < p; q++){
		if(q + (m - 1) * p >= n)
			break;
		int p1 = q - m * p, p2 = q;
		int sarj = 0;
		for(; p1 < n; p1 += p, p2 += p){
			if(p2 < n and po[p2] != -1){
				cnt2[po[p2]]++;
				if(cnt2[po[p2]] <= cnt[po[p2]])
					sarj++;
			}
			if(p1 >= 0 and po[p1] != -1){
				cnt2[po[p1]]--;
				if(cnt2[po[p1]] < cnt[po[p1]])
					sarj--;
			}
			if(p1 >= -p  and sarj == m)
				ans.PB(p1 + p + 1);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}