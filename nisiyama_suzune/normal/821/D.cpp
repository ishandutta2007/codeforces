#include <bits/stdc++.h>

const int INF = 1E9;

const int MAXN = 11000;

int N, M, K;
int R[11000], C[11000];
std::vector <int> cr[11000], cc[11000];

struct dijkstra {

	int dist[11000], last[11000];

	bool vis[11000];

	void solve (int s) {
		std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >,
		    std::greater <std::pair <int, int> > > queue;
		std::fill (dist, dist + MAXN, INF);
		std::fill (last, last + MAXN, -1);
		std::fill (vis, vis + MAXN, false);
		dist[s] = 0;
		queue.push (std::make_pair (0, s));
//		printf ("%d\n", s);
//		fflush (stdout);
		while (!queue.empty ()) {
			int n = queue.top ().second; queue.pop (); vis[n] = true;
			for (int i = 0; i < cr[R[n]].size (); ++i) {
				int v = cr[R[n]][i], c = std::abs (C[v] - C[n]) <= 1 ? 0 : 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			for (int i = 0; i < cc[C[n]].size (); ++i) {
				int v = cc[C[n]][i], c = std::abs (R[v] - R[n]) <= 1 ? 0 : 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (R[n] - 1 >= 0)
			for (int i = 0; i < cr[R[n] - 1].size (); ++i) {
				int v = cr[R[n] - 1][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (R[n] + 1 < N)
			for (int i = 0; i < cr[R[n] + 1].size (); ++i) {
				int v = cr[R[n] + 1][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (C[n] - 1 >= 0)
			for (int i = 0; i < cc[C[n] - 1].size (); ++i) {
				int v = cc[C[n] - 1][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (C[n] + 1 < M)
			for (int i = 0; i < cc[C[n] + 1].size (); ++i) {
				int v = cc[C[n] + 1][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (R[n] - 2 >= 0)
			for (int i = 0; i < cr[R[n] - 2].size (); ++i) {
				int v = cr[R[n] - 2][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (R[n] + 2 < N)
			for (int i = 0; i < cr[R[n] + 2].size (); ++i) {
				int v = cr[R[n] + 2][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (C[n] - 2 >= 0)
			for (int i = 0; i < cc[C[n] - 2].size (); ++i) {
				int v = cc[C[n] - 2][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			if (C[n] + 2 < M)
			for (int i = 0; i < cc[C[n] + 2].size (); ++i) {
				int v = cc[C[n] + 2][i], c = 1;
				if (dist[v] > dist[n] + c) {
					dist[v] = dist[n] + c; last[v] = n;
					queue.push (std::make_pair (dist[v], v));
				}
			}
			while (!queue.empty () && vis[queue.top ().second]) queue.pop ();
		}
	}

};

dijkstra d;

int ans = INF;

int main () {
	scanf ("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; ++i) {
		scanf ("%d%d", &R[i], &C[i]);
		cr[--R[i]].push_back (i);
		cc[--C[i]].push_back (i);
	}
	for (int i = 0; i < 10000; ++i) {
		sort (cr[i].begin (), cr[i].end (), [&] (const int &a, const int &b) { return C[a] < C[b]; });
		sort (cc[i].begin (), cc[i].end (), [&] (const int &a, const int &b) { return R[a] < R[b]; });
	}
	d.solve (cr[0].front ());
	for (int i = 0; i < cr[N - 2].size (); ++i)
		ans = std::min (ans, d.dist[cr[N - 2][i]] + 1);
	for (int i = 0; i < cc[M - 2].size (); ++i)
		ans = std::min (ans, d.dist[cc[M - 2][i]] + 1);
	for (int i = 0; i < cr[N - 1].size (); ++i)
		if (C[cr[N - 1][i]] == M - 1)
			ans = d.dist[cr[N - 1][i]];
		else
			ans = std::min (ans, d.dist[cr[N - 1][i]] + 1);
	for (int i = 0; i < cc[M - 1].size (); ++i)
		if (R[cc[M - 1][i]] == N - 1)
			ans = d.dist[cc[M - 1][i]];
		else
			ans = std::min (ans, d.dist[cc[M - 1][i]] + 1);
	printf ("%d\n", ans == INF ? -1 : ans);
}