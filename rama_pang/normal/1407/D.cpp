#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> H(N);
  vector<vector<int>> adj(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  vector<int> st;
  for (int i = N - 1; i >= 0; i--) {
    while (!st.empty() && H[st.back()] < H[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      adj[i].emplace_back(st.back());
    }
    st.emplace_back(i);
  }
  st.clear();
  for (int i = N - 1; i >= 0; i--) {
    while (!st.empty() && H[st.back()] > H[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      adj[i].emplace_back(st.back());
    }
    st.emplace_back(i);
  }
  st.clear();
  for (int i = 0; i < N; i++) {
    while (!st.empty() && H[st.back()] < H[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      adj[st.back()].emplace_back(i);
    }
    st.emplace_back(i);
  }
  st.clear();
  for (int i = 0; i < N; i++) {
    while (!st.empty() && H[st.back()] > H[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      adj[st.back()].emplace_back(i);
    }
    st.emplace_back(i);
  }
  vector<int> dist(N, -1);
  queue<int> q;
  q.emplace(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.emplace(v);
      }
    }
  }
  cout << dist[N - 1] << "\n";
  return 0;
}