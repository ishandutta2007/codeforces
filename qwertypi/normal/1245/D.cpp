#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[2000], k[2000];
int dis[2001][2001];
int pos[2000][2];
vector<pair<int, pair<int, int>>> pq;
int p[2001], s[2001];

int root(int x){
	if(x == p[x]) return x;
	return p[x] = root(p[x]);
}

bool join(int x, int y){
	int r_x = root(x), r_y = root(y);
	if(r_x == r_y){
		return false;
	}
	if(s[r_x] > s[r_y]){
		swap(r_x, r_y);
	}
	p[r_x] = p[r_y];
	s[r_y] += s[r_x];
	return true;
}

vector<int> ps;
vector<pair<int, int>> edges;
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++){
		p[i] = i;
		s[i] = 1;
	}
	for(int i = 0; i < n; i++){
		cin >> pos[i][0] >> pos[i][1];
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < n; i++){
		cin >> k[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int d = abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1]);
			pq.push_back({d * (k[i] + k[j]), {i + 1, j + 1}});
		}
	}
	for(int i = 0; i < n; i++){
		pq.push_back({c[i], {0, i + 1}});
	} 
	sort(pq.begin(), pq.end());
	int ans = 0;
	
	for(auto edge : pq){
		int w = edge.first;
		if(join(edge.second.first, edge.second.second)){
			ans += w;
			if(edge.second.first == 0){
				ps.push_back(edge.second.second);
			}else{
				edges.push_back(edge.second);
			}
		}
	}
	cout << ans << endl;
	cout << ps.size() << endl;
	for(auto i : ps){
		cout << i << ' ';
	}
	cout << endl;
	cout << edges.size() << endl;
	for(auto i : edges){
		cout << i.first << ' ' << i.second << endl;
	}
}