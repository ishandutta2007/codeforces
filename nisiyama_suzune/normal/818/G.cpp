#include <bits/stdc++.h>

const int MAXN = 10000, MAXM = 250000;
const int INF = 1E9;

struct cost_flow_edge_list {
	int size;
	int begin[MAXN], dest[MAXM], next[MAXM], cost[MAXM], flow[MAXM], inv[MAXM];
	void clear (int n) {
		size = 0;
		std::fill (begin, begin + n, -1);
	}
	cost_flow_edge_list (int n = MAXN) {
		clear (n);
	}
	void add_edge (int u, int v, int c, int f) {
		dest[size] = v; next[size] = begin[u]; cost[size] = c;
		flow[size] = f; inv[size] = size + 1; begin[u] = size++;
		dest[size] = u; next[size] = begin[v]; cost[size] = -c;
		flow[size] = 0; inv[size] = size - 1; begin[v] = size++;
	}
} e;

struct minimum_cost_flow {

	int n, source, target;
	int prev[MAXN];
	int dist[MAXN], occur[MAXN];

	bool augment (cost_flow_edge_list &e) {
		std::vector <int> queue;
		std::fill (dist, dist + n, INF);
		std::fill (occur, occur + n, 0);
		dist[source] = 0;
		occur[source] = true;
		queue.push_back (source);
		for (int head = 0; head < (int)queue.size(); ++head) {
			int x = queue[head];
			for (int i = e.begin[x]; ~i; i = e.next[i]) {
				int y = e.dest[i];
				if (e.flow[i] && dist[y] > dist[x] + e.cost[i]) {
					dist[y] = dist[x] + e.cost[i];
					prev[y] = i;
					if (!occur[y]) {
						occur[y] = true;
						queue.push_back (y);
					}
				}
			}
			occur[x] = false;
		}
		return dist[target] < INF;
	}

	std::pair <int, int> solve (cost_flow_edge_list &e, int n, int s, int t) {
		minimum_cost_flow::n = n;
		source = s; target = t;
		std::pair <int, int> answer = std::make_pair (0, 0);
		while (augment (e)) {
			int number = INF;
			for (int i = target; i != source; i = e.dest[e.inv[prev[i]]]) {
				number = std::min (number, e.flow[prev[i]]);
			}
			answer.first += number;
			for (int i = target; i != source; i = e.dest[e.inv[prev[i]]]) {
				e.flow[prev[i]] -= number;
				e.flow[e.inv[prev[i]]] += number;
				answer.second += number * e.cost[prev[i]];
			}
		}
		return answer;
	}

} _m;

int N;
int A[110000];
int le[110000], lm[10];
const int s = 9998, st = 9997, t = 9999;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> A[i];
	e.add_edge (st, s, 0, 4);
	for (int i = N - 1; i >= 0; --i) {
		int c = A[i];
		e.add_edge(s, 3 * i + 1, 0, 1);
		e.add_edge(3 * i + 2, 3 * i + 1, 0, INF);
		e.add_edge(3 * i + 1, 3 * i, -1, 1);
		e.add_edge(3 * i, t, 0, 1);
		int ie = le[c], ig = le[c + 1], il = le[c - 1], im = lm[c % 7];
		if (ie) e.add_edge(3 * i + 1, 3 * ie + 1, 0, INF);
		if (ig && (ig < ie || !ie)) e.add_edge(3 * i, 3 * ig + 1, 0, 1);
		if (il && (il < ie || !ie)) e.add_edge(3 * i, 3 * il + 1, 0, 1);
		if (im) e.add_edge(3 * i, 3 * im + 2, 0, 1), e.add_edge(3 * i + 2, 3 * im + 2, 0, INF);
		le[c] = lm[c % 7] = i;
	}
	std::cout << -_m.solve (e, 10000, st, t).second << std::endl;
}