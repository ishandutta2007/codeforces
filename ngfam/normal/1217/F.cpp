#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000100;
const int magic = 1200;
 
int n, q;
pair < int, int > queries[N], idQuery[N];
 
int t[N];
int a[N];
int b[N];
 
int e[N];
int head[N];
int link[N];
 
int szque;
int que[N];
int visited[N];
 
int lab[N];
int inQueue[N];
int existing[N];
 
int find(int x) {
  return (lab[x] < 0 ? x : lab[x] = find(lab[x]));
}
 
void join(int x, int y) {
  x = find(x); y = find(y);
  if(x == y) return;
  if(lab[x] > lab[y]) swap(x, y);
  lab[x] += lab[y];
  lab[y] = x;
}
 
int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 
 
  cin >> n >> q;
 
  vector < pair < int, int > > edges;
 
  for(int i = 1; i <= q; ++i) {
    cin >> t[i] >> a[i] >> b[i];
    if(t[i] == 2) continue;
    queries[i] = make_pair(a[i], b[i]);
    edges.emplace_back(a[i], b[i]);
    edges.emplace_back(a[i] % n + 1, b[i] % n + 1);
  }
 
  for(auto &p : edges) if(p.first > p.second) swap(p.first, p.second);
 
  sort(edges.begin(), edges.end());
  edges.erase(unique(edges.begin(), edges.end()), edges.end());
 
  for(int i = 1; i <= q; ++i) {
    if(t[i] == 2) continue;
    pair < int, int > x = queries[i];
    pair < int, int > y = {x.first % n + 1, x.second % n + 1};
    if(x.first > x.second) swap(x.first, x.second);
    if(y.first > y.second) swap(y.first, y.second);
    int id1 = lower_bound(edges.begin(), edges.end(), x) - edges.begin();
    int id2 = lower_bound(edges.begin(), edges.end(), y) - edges.begin();
    idQuery[i] = make_pair(id1, id2);
  } 
 
  int last = 0;
 
  for(int lo = 1; lo <= q; lo += magic) {
    int hi = min(q, lo + magic - 1);
    for(int i = lo; i <= hi; ++i) {
      inQueue[idQuery[i].first] = 1;
      inQueue[idQuery[i].second] = 1;
    }
 
    int cnt = 0;
    fill(head + 1, head + n + 1, 0);
    fill(lab + 1, lab + n + 1, -1);
    for(int i = 0; i < edges.size(); ++i) {
      if(!inQueue[i]) {
        if(existing[i]) join(edges[i].first, edges[i].second);
      }
      else {
 
      } 
    }
 
    for(int i = 0; i < edges.size(); ++i) {
      if(!inQueue[i]) {
      }
      else {
        pair < int, int > old = edges[i];
        edges[i] = {find(old.first), find(old.second)};
        if(edges[i].first == edges[i].second) {
          edges[i] = old;
          continue;
        }
        e[++cnt] = i;
        if(head[edges[i].first] == 0) {
          link[cnt] = 0;
          head[edges[i].first] = cnt;
        }
        else {
          link[cnt] = head[edges[i].first]; 
          head[edges[i].first] = cnt;
        }
 
        e[++cnt] = i;
        if(head[edges[i].second] == 0) {
          link[cnt] = 0;
          head[edges[i].second] = cnt;
        }
        else {
          link[cnt] = head[edges[i].second];
          head[edges[i].second] = cnt;
        }
        edges[i] = old;
      } 
    }
 
    for(int i = lo; i <= hi; ++i) {
      if(t[i] == 1) {
        int id = (last ? idQuery[i].second : idQuery[i].first);
        existing[id] ^= 1;
      }
      else {
        int st = a[i] + last, en = b[i] + last;
        if(st > n) st = 1; if(en > n) en = 1;
        st = find(st); en = find(en);
        que[szque = 1] = st;
        last = 0;
        for(int w = 1; w <= szque; ++w) {
          int v = que[w];
          if(v == en) {
            last = 1;
          }
          for(int s = head[v]; s != 0; s = link[s]) {
            if(!existing[e[s]]) continue;
            int ns = v ^ find(edges[e[s]].first) ^ find(edges[e[s]].second);
            if(visited[ns]) continue;
            visited[ns] = 1;
            que[++szque] = ns;
          } 
        }
        for(int i = 1; i <= szque; ++i) visited[que[i]] = 0;
        szque = 0;
        cout << last;
      }
    }
 
    for(int i = lo; i <= hi; ++i) {
      inQueue[idQuery[i].first] = 0;
      inQueue[idQuery[i].second] = 0;
    }
  }
 
  return 0;
}