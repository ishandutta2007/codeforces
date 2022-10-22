#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, a, idx[1505], col[1505][1505], thing[1505], rv[1505], c[1505], c1[1505];
vector<int> v[1505], v1[1505];
map<vector<int>, queue<int> > ma;
stack<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a;
			v[i].pb(a);
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a;
			v1[i].pb(a);
		}
		ma[v1[i]].push(i);
	}
	for (int i=0; i<n; i++){
		if (ma[v[i]].empty()){
			cout << -1;
			return 0;
		}
		idx[i] = ma[v[i]].front();
		rv[idx[i]] = i;
		//cout << idx[i] << "\n";
		ma[v[i]].pop();
	}
	for (int i=0; i<n-1; i++){
		for (int j=0; j<m; j++){
			if (v1[i][j] > v1[i+1][j]) col[i][j] = -1;
			else if (v1[i][j] == v1[i+1][j]) col[i][j] = 0;
			else col[i][j] = 1;
		}
	}
	for (int i=0; i<n-1; i++){
		if (rv[i] < rv[i+1]) col[i][m] = 1;
		else col[i][m] = -1;
	}
	for (int j=0; j<=m; j++){
		for (int i=0; i<n-1; i++){
			if (col[i][j] == -1) c[j]++;
			if (col[i][j] == 1) c1[j]++;
		}
	}
	queue<int> q, q1;
	set<int> s;
	for (int i=0; i<n-1; i++){
		s.insert(i);
	}
	for (int j=0; j<m; j++){
		if (c[j] == 0 && c1[j] > 0){
			q.push(j);
		}
	}
	set<int>::iterator it;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		if (c1[x] == 0) continue;
		ans.push(x);
		for (it = s.begin(); it != s.end(); it++){
			if (col[*it][x] == 1) q1.push(*it);
		}
		while (!q1.empty()){
			int y = q1.front();
			q1.pop();
			for (int j=0; j<m; j++){
				if (col[y][j] == 1) c1[j]--;
				if (col[y][j] == -1){
					c[j]--;
					if (c[j] == 0) q.push(j);
				}
			}
			s.erase(y);
		}
	}
	bool gd = true;
	for (it = s.begin(); it != s.end(); it++){
		//cout << *it << "\n";
		if (col[*it][m] != 1) gd = false;
	}
	if (!gd) cout << -1;
	else {
		cout << ans.size() << "\n";
		while (!ans.empty()){
			cout << ans.top()+1 << " ";
			ans.pop();
		}
	}
}