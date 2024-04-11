#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, md, mn, A[505];
vector<int> adj[505], zvv;

void dfs(int n, int e, int d) {
	if (d >= md) {
		md = d;
		mn = n;
	}
	for (auto u : adj[n])
		if (u != e) dfs(u, n, d + 1);
}

main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] == 1) zvv.push_back(i);
	}
	if (zvv.size() == 0) {
		cout << "YES " << N - 1 << '\n' << N - 1 << '\n';
		for (int i = 1; i < N; i++)
			cout << i << ' ' << i + 1 << '\n';
		return 0;
	} else if (zvv.size() == 1) {
		cout << "YES " << N - 1 << '\n' << N - 1 << '\n';
		if (zvv[0] == N || zvv[0] == 1) {
			for (int i = 1; i < N; i++)
				cout << i << ' ' << i + 1 << '\n';
		} else {
			cout << zvv[0] << ' ' << zvv[0] + 1 << '\n' << zvv[0] + 1 << ' ' << 1 << '\n';
			for (int i = 1; i < zvv[0] - 1; i++)
				cout << i << ' ' << i + 1 << '\n';
			cout << zvv[0] - 1 << ' ' << zvv[0] + 2 << '\n';
			for (int i = zvv[0] + 2; i < N; i++)
				cout << i << ' ' << i + 1 << '\n';
		}
		return 0;
	} else if (zvv.size() == 2) {
		cout << "YES " << N - 1 << '\n' << N - 1 << '\n';
		vector<int> v;
		for (int i = 1; i <= N; i++)
			if (i != zvv[0] && i != zvv[1]) v.push_back(i);
		cout << zvv[0] << ' ' << v[0] << '\n';
		for (int i = 0; i < v.size() - 1; i++)
			cout << v[i] << ' ' << v[i + 1] << '\n';
		cout << v.back() << ' ' << zvv[1] << '\n';
	} else {
		int b1 = zvv.back(), b2 = zvv[zvv.size() - 2], of = 0;
		vector<int> v;
		zvv.pop_back();
		zvv.pop_back();
		for (int i = 1; i <= N; i++) {
			if (A[i] == 1) continue;
			v.push_back(i);
			of += A[i] - 2;
		}
		if (of < zvv.size()) {
			cout << "NO\n";
			return 0;
		}
		for (int i = 0; i < v.size() - 1; i++)
			adj[v[i]].push_back(v[i + 1]),
			adj[v[i + 1]].push_back(v[i]);
		adj[v[0]].push_back(b1);
		adj[b1].push_back(v[0]);
		adj[v.back()].push_back(b2);
		adj[b2].push_back(v.back());
		for (int i = 1; i <= N; i++) {
			if (A[i] == 1) continue;
			A[i] -= 2;
			while (A[i] && !zvv.empty()) {
				adj[i].push_back(zvv.back());
				adj[zvv.back()].push_back(i);
				zvv.pop_back();
				A[i]--;
			}
		}
		dfs(1, -1, 0);
		dfs(mn, -1, 0);
		cout << "YES " << md << '\n' << N - 1 << '\n';
		for (int i = 1; i <= N; i++)
			for (int j : adj[i])
				if (i > j) cout << i << ' ' << j << '\n';
	}
}