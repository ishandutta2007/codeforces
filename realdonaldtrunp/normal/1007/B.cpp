#include<bits/stdc++.h>
using namespace std;

int t;

vector<vector<pair<int, long long int> > > dp;

vector<int > d[100002];

int us[100002];
int u_s;
int mp[100002];

int uniq[100002];
int uni;

long long int sz[(1 << 3)];

set<vector<int> > s;
int main(){
	int mx = 0;
	for (int i = 1; i < 100002; i++){
		for (int j = 1; j*j <= i; j++){
			if (i%j == 0){
				d[i].push_back({ j });
				if (i / j != j)d[i].push_back({ i / j });
			}
			sort(d[i].begin(), d[i].end());
			mx = max(mx, (int)d[i].size());
		}
	}
	for (int i = 0; i < (1 << 3); i++){
		for (int j = 0; j < (1 << 3); j++){
			for (int k = 0; k < (1 << 3); k++){
				if (i & 1){
					if ((j >> 1) & 1){
						if ((k >> 2) & 1){
							if (i == j&&j == k)continue;
							vector<int> valid;
							valid.push_back(i);
							valid.push_back(j);
							valid.push_back(k);
							sort(valid.begin(), valid.end());
							s.insert(valid);
						}
					}
				}
			}
		}
	}
	cin >> t;
	while (t--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int ar[] = { a, b, c };
		u_s++;
		uni = 0;
		for (int i = 0; i < 3; i++){
			for (int el : d[ar[i]]){
				if (us[el] == u_s){
					mp[el] |= (1 << i);
				}
				else{
					mp[el] = 0;
					us[el] = u_s;
					mp[el] |= (1 << i);
					uniq[uni] = el;
					uni++;
				}
			}
		}
		memset(sz, 0, sizeof(sz));
		for (int i = 0; i < uni; i++){
			sz[mp[uniq[i]]]++;
		}
		long long int ans = 0;
		//three
		{
			long long int val = sz[(1 << 3) - 1];
			ans += val*(val - 1LL)*(val - 2LL) / 6;  //different
			ans += sz[(1 << 3) - 1];//same
			ans += val*(val - 1LL);//
		}
		for (auto &it : s){
			if (it[0] == it[1]){
				ans += (sz[it[0]] + sz[it[0]] * (sz[it[0]] - 1) / 2) * sz[it[2]];
				continue;
			}
			if (it[1] == it[2]){
				ans += sz[it[0]] * (sz[it[1]] + sz[it[1]] * (sz[it[2]] - 1) / 2LL);
				continue;
			}
			ans += sz[it[0]] * sz[it[1]] * sz[it[2]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}