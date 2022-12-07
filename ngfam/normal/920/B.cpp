#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];
int ans[N];
vector < int > idx[N];

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		for(int i = 1; i <= 5000; ++i) idx[i].clear();

		for(int i = 1; i <= n; ++i){
			int l;
			cin >> l >> a[i];
			idx[l].push_back(i);
		}


		queue < pair < int, int > > f;

		memset(ans, 0, sizeof ans);

		for(int i = 1; i <= 5000; ++i){
			for(int t : idx[i]){
				f.emplace(t, a[t]);
			}
			while(!f.empty() && f.front().second < i) f.pop();


			if(!f.empty()) {
				ans[f.front().first] = i;
				f.pop();
			}
		}
		
		for(int i = 1; i <= n; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}