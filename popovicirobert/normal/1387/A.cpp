#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

 	cin >> n >> m;

 	vector<vector<pair<int, int>>> g(n + 1);
 	for(i = 1; i <= m; i++) {
 		int x, y, z;
 		cin >> x >> y >> z;
 		g[x].push_back({y, z});
 		g[y].push_back({x, z});
 	}

 	vector<int> coef(n + 1), constant(n + 1);
 	vector<bool> vis(n + 1);

 	function <void(int, vector<int>&)> dfs = [&](int nod, vector<int>& nodes) {
 		nodes.push_back(nod);
 		vis[nod] = 1;

 		for(auto it : g[nod]) {
 			if(vis[it.first] == 0) {
 				constant[it.first] = it.second - constant[nod];
 				coef[it.first] = -coef[nod];
 				dfs(it.first, nodes);
 			}
 		}
 	};

 	vector<double> sol(n + 1);

 	auto solve = [&](const vector<int>& nodes) {
 		set<pair<int, int>> values;

	 	for(auto a : nodes) {
	 		for(auto it : g[a]) {
	 			int b, sum;
	 			tie(b, sum) = it;

	 			int ct = constant[a] + constant[b];
	 			int cf = coef[a] + coef[b];

	 			if(cf == 0) {
	 				if(ct != sum) {
	 					cout << "NO" << endl;
	 					exit(0);
	 				}
	 			}
	 			else {
	 				int g = __gcd(sum - ct, cf);
	 				values.insert({(sum - ct) / g, cf / g});
	 			}
	 		}
	 	}

	 	double value;

	 	if((int)values.size() > 1) {
	 		cout << "NO" << endl;
	 		exit(0);
	 	}
	 	else if((int)values.size() == 1) {
	 		value = 1.0 * values.begin() -> first / values.begin() -> second;
	 	}
	 	else {
		 	ll sumCoef = 0, sumConstant = 0;
		 	vector<pair<int, int>> events;

		 	for(auto i : nodes) {
		 		//cerr << coef[i] << " " << constant[i] << "  "; 
		 		if(coef[i] < 0) {
		 			sumCoef += coef[i];
		 			sumConstant += constant[i];
		 			events.push_back({constant[i], coef[i]});
		 		}
		 		else {
		 			sumCoef -= coef[i];
		 			sumConstant -= constant[i];
		 			events.push_back({-constant[i], coef[i]});
		 		}
		 	}

		 	sort(events.begin(), events.end());
		 	ll ans = 1e18;

		 	for(auto e : events) {
		 		if(e.second < 0) {
		 			sumCoef -= 2LL * e.second;
		 			sumConstant -= 2LL * e.first;
		 		}
		 		else {
		 			sumCoef += 2LL * e.second;
		 			sumConstant -= 2LL * e.first;
		 		}

		 		ll cur = 1LL * e.first * sumCoef + sumConstant;
		 		if(cur < ans) {
		 			ans = cur;
		 			value = e.first;
		 		}
		 	}
	 	}

	 	for(auto nod : nodes) {
	 		sol[nod] = value * coef[nod] + constant[nod];
	 	}
 	};

 	for(i = 1; i <= n; i++) {
 		if(vis[i] == 0) {
 			vector<int> nodes;

 			constant[i] = 0;
 			coef[i] = 1;
 			
 			dfs(i, nodes);

 			solve(nodes);
 		}
 	}

 	cout << "YES\n";
 	for(i = 1; i <= n; i++) {
 		cout << fixed << setprecision(20) << sol[i] << " ";
 	}


    return 0;
}