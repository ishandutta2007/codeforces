#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define siktir exit(0)

const int maxn = 1e5 + 85 - 69;
vector<int> v[maxn];
int ans[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v[x].PB(i);
	}
	int p = 1e5, cnt = 0;
	while(p > 0){
		if(v[p].size()){
			cnt++;
			for(int i = p; i > 0; i--){
				if(v[i].size() == 0){
					cout << -1 << endl;
					siktir;
				}
				ans[v[i].back()] = cnt;
				v[i].pop_back();
			}
		}
		else
			p--;
	}
	cout << cnt << endl;
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}