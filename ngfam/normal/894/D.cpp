#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m, cnt;
int len[N];

long long f[N];

void dfs(int x){
	if(x + x <= n){
		f[x + x] = f[x] + len[x + x - 1];
		dfs(x + x);
	}
	if(x + x + 1 <= n){
		f[x + x + 1] = f[x] + len[x + x];
		dfs(x + x + 1);
	}
}

vector < long long > tmp;
vector < long long > cal;
vector < long long > L[N];
vector < long long > R[N];
vector < long long > preL[N];
vector < long long > preR[N];

void again(int u){
	if(u + u <= n){
		again(u + u);
		tmp[0] = f[u + u];


		cal.resize(L[u + u].size() + R[u + u].size());
		merge(L[u + u].begin(), L[u + u].end(), R[u + u].begin(), R[u + u].end(), cal.begin());

		L[u].resize(cal.size() + 1);
		merge(cal.begin(), cal.end(), tmp.begin(), tmp.end(), L[u].begin());
	}
	if(u + u + 1 <= n){
		again(u + u + 1);
		tmp[0] = f[u + u + 1];

		cal.resize(L[u + u + 1].size() + R[u + u + 1].size());
		merge(L[u + u + 1].begin(), L[u + u + 1].end(), R[u + u + 1].begin(), R[u + u + 1].end(), cal.begin());

		R[u].resize(cal.size() + 1);
		merge(cal.begin(), cal.end(), tmp.begin(), tmp.end(), R[u].begin());
	}
}

pair < int, long long > calc(vector < long long > &num, vector < long long > &sum, long long x, long long y){
	int l = lower_bound(num.begin(), num.end(), x) - num.begin(); 
	int r = (upper_bound(num.begin(), num.end(), y) - num.begin()) - 1;
	if(r < 0) return make_pair(0, 0);

	if(l == 0){
		return make_pair(r + 1, sum[r]);
	} 
	return make_pair(r - l + 1, sum[r] - sum[l - 1]);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &m);

	for(int i = 1; i < n; ++i){
		scanf("%d", len + i);
	}

	dfs(1);
	tmp.resize(1);

	again(1);

	for(int i = 1; i <= n; ++i){
		preL[i].resize(L[i].size());
		preR[i].resize(R[i].size());

		partial_sum(L[i].begin(), L[i].end(), preL[i].begin());
		partial_sum(R[i].begin(), R[i].end(), preR[i].begin());
	}

	for(int i = 1; i <= m; ++i){
		int x, h;
		scanf("%d%d", &x, &h);
		
		long long tot = 0;
		int sub = 1;
		auto l = calc(R[x], preR[x], f[x], h + f[x]);
		auto r = calc(L[x], preL[x], f[x], h + f[x]);
		
		tot += l.second + r.second - 1LL * (l.first + r.first) * f[x];
		sub += l.first + r.first;

		long long root = 0;
			int save = x;

		while(true){
			if(x == 1) break;
			int p = x / 2;
			
			root += len[x - 1];
			if(root > h) break;
			tot += root;
			++sub;



			if(p + p == x){
				auto curr = calc(R[p], preR[p], 0, h - f[save] + 2 * f[p]);
				tot += curr.second + 1LL * curr.first * (-2 * f[p] + f[save]);  
				sub += curr.first;
			}
			else{
				auto curr = calc(L[p], preL[p], 0, h - f[save] + 2 * f[p]);
				tot += curr.second + 1LL * curr.first * (-2 * f[p] + f[save]);  
				sub += curr.first;
			}
			x = p;
		}
		printf("%lld\n", 1LL * sub * h - tot);
	}


	return 0;
}