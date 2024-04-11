#include <iostream>
#include <vector>

using namespace std;

int n, m, k, l, r;
int roadFr[10000];
int roadTo[10000];
int was[500];
int fr, to;

vector< vector<int> > g;

vector< vector<int> > g1;
vector< vector<int> > g2;

void go(int v) {
	was[v] = 1;
	for (int i = 0; i < g1[v].size(); i++) {
		int it = g1[v][i];
		if (it >= l)
			break;
		int next = roadFr[it] + roadTo[it] - v;
		if (was[next] == 0) 
			go(next);
	}
	for (int i = g2[v].size() - 1; i >= 0; i--) {
		int it = g2[v][i];
		if (it <= r)
			break;
		int next = roadFr[it] + roadTo[it] - v;
		if (was[next] == 0) 
			go(next);
	}
}

int p[500];
int sz[500];

int get(int v) {
	if (p[v] == v)
		return v;
	p[v] = get(p[v]);
	return p[v];
}

void union1(int v1, int v2) {
	v1 = get(v1);
	v2 = get(v2);
	if (v1 == v2)
		return;
	if (sz[v1] < sz[v2]) {
		int tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	p[v2] =v1;
}

int used1[10000];
int used2[10000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		g.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		g1.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		g2.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &fr, &to);
		fr--; to--;
		roadFr[i] = fr;
		roadTo[i] = to;
		g[fr].push_back(i);
		g[to].push_back(i);
	}

	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		sz[i] = 0;
	
	for (int i = 0; i < m; i++) {
		if (get(roadFr[i]) == get(roadTo[i])) {
			used1[i] = 0;
		} else {
			used1[i] = 1;
			union1(roadFr[i], roadTo[i]);
		}
	}


	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		sz[i] = 0;
	
	for (int i = m - 1; i >= 0; i--) {
		if (get(roadFr[i]) == get(roadTo[i])) {
			used2[i] = 0;
		} else {
			used2[i] = 1;
			union1(roadFr[i], roadTo[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (used1[g[i][j]])
				g1[i].push_back(g[i][j]);
			if (used2[g[i][j]])
				g2[i].push_back(g[i][j]);
		}
	}

	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d%d", &l, &r);
		l--; r--;
		for (int j = 0; j < n; j++)
			was[j] = 0;
		int res = 0;
		for (int j = 0; j < n; j++) {
			if (was[j] == 0) {
				res++;
				go(j);
			}
		}
		printf("%d\n", res);
	}
}