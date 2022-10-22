#include <bits/stdc++.h>
using namespace std;

int GEN_SIZE = 6;
vector<int> v, adj[50005];
int match[50005], match2[50005],  vis[50005], ans[50005];
int V,Vleft;

int conv(vector<int> v, int s) {
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans *= s;
		ans += v[i];
	}
	return ans;
}

vector<int> unconv(int p, int s) {
	vector<int> v1;
	for (int i = 0; i < s; i++) {
		v1.push_back(p % s);
		p /= s;
	}
	reverse(v1.begin(), v1.end());
	return v1;
}

void recur(int x) {
	if (x == GEN_SIZE) {
		int rval = conv(v, GEN_SIZE);
		for (int rem = 0; rem < GEN_SIZE; rem++) {
			vector<int> tmp_v;
			tmp_v.push_back(rem);
			for (int i = 0; i < GEN_SIZE; i++) if (rem != i) tmp_v.push_back(v[i]);
			int lval = conv(tmp_v, GEN_SIZE);
			adj[rval].push_back(lval);
		}
		return;
	}
	for (int i = 0; i < GEN_SIZE; i++) {
		v.push_back(i);
		recur(x + 1);
		v.pop_back();
	}
}
	
	
int aug(int v) {
	if (vis[v]) return 0; 
	vis[v] = 1;
	for (int j = 0; j < (int)adj[v].size(); j++) {
		int r = adj[v][j];
		if (match[r] == -1) {
			match[r] = v; return 1;
		}
	}
	for (int j = 0; j < (int)adj[v].size(); j++) {
		int r = adj[v][j];
		if (aug(match[r])) {
			match[r] = v; return 1;
		}
	}
	return 0;
}

int T;
vector< pair< pair<int, int>, int> > q;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, R;
		scanf("%d%d", &N, &R);
		vector<int> v1;
		v1.push_back(R - 1);
		for (int j = 0; j < N - 1; j++) {
			int x;
			scanf("%d", &x);
			v1.push_back(x - 1);
		}
		int val = conv(v1, N);
		q.push_back(make_pair(make_pair(N, val), i));
	}
	sort(q.begin(), q.end());
	int curN = 0;
	for (int i = 0; i < q.size(); i++) {
		if (curN != q[i].first.first) {
			curN = q[i].first.first;
			GEN_SIZE = curN;
			
			memset(match, -1, sizeof(match));
			int v = 1;
			for (int i = 0; i < GEN_SIZE; i++) {
				v *= GEN_SIZE;
			}
			for (int i = 0; i < v; i++) adj[i].clear();
			recur(0);
			for (int i = 0; i < v; i++) {
				memset(vis, 0, sizeof(vis));
				aug(i);
			}
			for (int i = 0; i < v; i++) match2[match[i]] = i;
			//printf("did matching for %d\n", curN);
		}
		vector<int> qv = unconv(q[i].first.second, curN);
		vector<int> v1 = unconv(match[q[i].first.second], curN);
		
		ans[q[i].second] = v1[qv[0]] + 1;
	}
	
	for (int i = 0; i < T; i++) printf("%d\n", ans[i]);
	
}