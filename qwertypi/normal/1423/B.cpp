#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u, v, w;
	bool operator< (const Edge& o){
		return w < o.w;
	}
};

vector<Edge> E;

int n, m;
bool visited[20001];
vector<int> cc;

vector<set<int>> H(20001);
vector<int> pq;
bool okay[20001];

void dfs(int v){
	visited[v] = true;
	cc.push_back(v);
	for(auto i : H[v]){
		if(!visited[i]){
			dfs(i);
		}
	}
}

void remove(int a, int b){
	// cout << "rm " << a << ' ' << b << endl;
	for(auto i : H[a]){
		H[i].erase(a);
		if(H[i].size() == 1){
			pq.push_back(i);
		}
	}
	for(auto i : H[b]){
		H[i].erase(b);
		if(H[i].size() == 1){
			pq.push_back(i);
		}
	}
	H[a].clear();
	H[b].clear();
	okay[a] = okay[b] = true;
}

bool check(vector<int> vi){
	pq.clear();
	for(auto i : vi){
		if(H[i].size() == 1) pq.push_back(i);
	}
	while(pq.size()){
		int fi = pq.back();
		// cout << fi << endl;
		pq.pop_back();
		if(H[fi].size() == 0){
			if(okay[fi]) continue;
			return false; // never occur
		}
		int v = *(H[fi].begin());
		remove(fi, v);
	}
	for(auto i : vi){
		if(!okay[i] && H[i].size() < 2) return false;
	}
	return true;
}

bool test(int x){
	// cout << "t" << ' ' << x << endl;
	cc.clear();
	for(int i = 0; i < n * 2; i++){
		H[i].clear();
	}
	fill(visited, visited + n * 2 + 1, 0);
	for(int i = 0; i < x; i++){
		H[E[i].u].insert(E[i].v);
		H[E[i].v].insert(E[i].u);
		// cout << E[i].u << ' ' << E[i].v << endl;
	}
	bool fail = false;
	for(int i = 0; i < n * 2; i++){
		if(visited[i]) continue;
		dfs(i);
		int a = 0;
		
		// cout << x << ' ' << i << ' ' << cc.size() << endl;
		// for(auto i : cc){
		// 	cout << i << ' ';
		// }
		// cout << endl;
		for(int i = 0; i < cc.size(); i++) a += cc[i] < n;
		if((int) cc.size() != a * 2) return false;
		// cout << "CA" << endl;
		if(!check(cc)){
			// cout << "SE" << endl; 
			fail = true;
			break;
		}
		cc.clear();
	}
	return !fail;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		E.push_back({u, v + n, d});
	}
	sort(E.begin(), E.end());
	int l = 0, r = m + 1;
	while(l != r){
		int mid = (l + r) / 2;
		if(test(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << (l == m + 1 ? -1 : E[l - 1].w) << endl;
}