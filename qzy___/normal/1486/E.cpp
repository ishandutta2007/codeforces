#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair 
 
using namespace std;
 
const int N = 1e5 + 10;
typedef long long ll;
 
int n , m;
vector <pair<int,int> > G[N];
 
struct Node {
	int p , w; ll s;
};
bool operator < (Node A , Node B) {
	return A.s != B.s ? A.s > B.s : A.w > B.w;
}
 
priority_queue <Node> q;
ll dis[N][52];
 
const ll inf = 0x3f3f3f3f3f3f3f3f;
 
int main() {
	ios::sync_with_stdio(false); 
	memset(dis , 0x3f , sizeof dis);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int a , b , c;
		cin >> a >> b >> c;
		G[a].push_back(mp(b , c)) , G[b].push_back(mp(a , c));
	}
	dis[1][0] = 0 , q.push((Node){1 , 0 , 0});
	while(!q.empty()) {
		Node t = q.top(); q.pop();
		int p = t.p , w = t.w; ll s = t.s;
		if(dis[p][w] < s) continue;
		for(auto i : G[p]) {
			int to = i.first , wt = i.second;
			if(w == 0) {
				if(dis[to][wt] > dis[p][w]) {
					dis[to][wt] = dis[p][w];
					q.push((Node){to , wt , dis[to][wt]});
				}
			}
			else {
				if(dis[to][0] > dis[p][w] + (wt + w) * (wt + w)) {
					dis[to][0] = dis[p][w] + (wt + w) * (wt + w);
					q.push((Node){to , 0 , dis[to][0]});
				}
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << (dis[i][0] == inf ? -1 : dis[i][0]) << " ";
	cout << endl;
	return 0;
}