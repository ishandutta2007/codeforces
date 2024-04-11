#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
long long mod = 1e9 + 7;

int n, cnt[M * 10], done[M], belong[M], num, m, sleep[M];
vector < int > a[N];

long long ifx[M];
              
bool cmp(pair < int, int > u, pair < int, int > v){
	if(u.first == v.first) return belong[u.second] < belong[v.second];
	return u.first < v.first;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int sz; scanf("%d", &sz);
		for(int j = 0; j < sz; ++j){
			int val; scanf("%d", &val);
			a[i].push_back(val);
		}
	}

	int app = m;

	for(int i = 1; i <= n; ++i){
	        a[i].push_back(m + 1);
		sort(a[i].begin(), a[i].end());
		
		vector < pair < int, int > > curr;

		int rem = 1;
		for(int j = 1; j < a[i].size(); ++j){
			int val = a[i][j], sif = a[i][j - 1];
		        if(!sleep[sif]){
		        	--app;
		        	sleep[sif] = 1;
		        }
			if(val != sif){
				curr.push_back(make_pair(rem, sif));
				rem = 1;	
			}	
			else{
				++rem;
			}
		}

		sort(curr.begin(), curr.end(), cmp);

		for(int j = 0; j < curr.size(); ++j){
			pair < int, int > val = curr[j];
			int sl = 0;

			int pter = j;

			while(pter < curr.size() && curr[pter].first == val.first && belong[curr[pter].second] == belong[val.second]){
				++pter;
				++sl;
			}

			int team = belong[curr[j].second];
			if(cnt[team] != sl){
				cnt[team] -= sl;
				++num;
				cnt[num] = sl;
				for(int pter = j; pter < j + sl; ++pter){
					belong[curr[pter].second] = num;
				}
			}
			j = pter - 1;
		}
	}


	ifx[0] = 1;
	for(int i = 1; i <= m; ++i){
		ifx[i] = ifx[i - 1]  * i;
		ifx[i] %= mod;
	}

	for(int i = 1; i <= m; ++i){
	//	cout << belong[i] << endl;
	}
	//cout << endl;

	long long ans = ifx[app];

	for(int i = 1; i <= num; ++i){
		ans = ans * ifx[cnt[i]];
		ans %= mod; 		
	}

	cout << ans;

	return 0;
}