#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 200 + 85 - 69, maxk = maxn * maxn * 2;
bool mark[maxk];
vector<int> all, v[maxn], has[maxn * maxn * 2];
set<int> s[maxn * (maxn - 1) / 2];
int n, cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n * (n - 1) / 2; i++){
		int c;
		cin >> c;
		while(c--){
			int x;
			cin >> x;
			s[i].insert(x);
			all.PB(x);
		}
	}
	if(n == 2){
		cout << 1 << ' ' << all[0] << endl;
		cout << all.size() - 1 << ' ';
		for(int i = 1; i < all.size(); i++)
			cout << all[i] << ' ';
		cout << endl;
		return 0;
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n * (n - 1) / 2; i++){
		for(auto x : s[i]){
			int id = lower_bound(all.begin(), all.end(), x) - all.begin();
			has[id].PB(i);
		}
	}
	for(int i = 0; i < all.size(); i++) if(!mark[i]){
		mark[i] = true;
		v[++cnt].PB(all[i]);
		for(int j = i + 1; j < all.size(); j++) if(!mark[j]){
			bool found = true;
			for(int k : has[i])
				if(s[k].find(all[i]) != s[k].end())
					if(s[k].find(all[j]) == s[k].end()){
						found = false;
						break;
					}
			if(found)
				v[cnt].PB(all[j]), mark[j] = true;
		}
	}
	for(int i = 1; i <= cnt; i++){
		cout << v[i].size() << ' ';
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}