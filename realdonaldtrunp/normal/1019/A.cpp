/**
*    author:  t0urist
*    created: 10.08.1919 11:45:14
**/
#include<bits/stdc++.h>

using namespace std;

int n;
int m;
vector<pair<long long int,int> > v[3002];
bool use[3002];
vector<pair<long long int, int> > vv;

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int p, c;
		scanf("%d%d", &p, &c);
		p--;
		v[p].push_back(make_pair(c,i) );
		if(p!=0)vv.push_back(make_pair(c, i));
	}
	for (int i = 0; i < m; i++)sort(v[i].begin(), v[i].end());
	sort(vv.begin(), vv.end());
	long long int need = LLONG_MAX;
	for (int i = 1; i <= n; i++){
		memset(use, false, sizeof(use));
		long long int ans = 0;
		int cur = v[0].size();
		for (int j = 1; j < m; j++){
			if (i <= v[j].size()){
				int ex = v[j].size() - i + 1;
				for (int k = 0; k < ex; k++){
					use[v[j][k].second] = true;
					ans += v[j][k].first;
					cur++;
				}
			}
		}
		for (int j = 0; j < vv.size()&&cur<i; j++){
			if (use[vv[j].second])continue;
			ans += vv[j].first;
			cur++;
		}
		need = min(need, ans);
	}
	printf("%lld\n", need);
	return 0;
}