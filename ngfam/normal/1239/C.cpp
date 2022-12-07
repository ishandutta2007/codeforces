#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
int n;
int pos[N];
int done[N];
int rev[N << 2];
long long T[N << 2];
long long p, timing, t[N], res[N];
 
#define mid ((l + r) >> 1)
 
void build(int x, int l, int r) {
  if(l == r) {
    T[x] = t[r];
    pos[r] = x;
    rev[x] = r;
    return;
  }
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
  T[x] = min(T[x + x], T[x + x + 1]);
}
 
void del(int x) {
  for(int node = pos[x]; node > 0; node >>= 1) {
    if(node == pos[x]) T[node] = 1e18;
    else T[node] = min(T[node + node], T[node + node + 1]);
  }
}
 
 
queue < int > qu;
set < int > inqueue;
 
 
void toqueue(int x) {
  del(x);
  qu.push(x);
  inqueue.insert(x);
  done[x] = 1;
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  cin >> n >> p;
 
  vector < pair < long long, int > > people;
 
  for(int i = 1; i <= n; ++i) {
    cin >> t[i];
    people.emplace_back(t[i], i);
  }
 
  build(1, 1, n);
 
  int it = 0;
  sort(people.begin(), people.end());
 
  while(true) {
    if(!qu.empty()) {
      int x = qu.front();
      qu.pop();
      timing = res[x] = timing + p;
 
      long long last = timing;
      vector < int > inds;
 
      while(true) {
        int to = (inqueue.empty() ? n : *inqueue.begin() - 1);
        int ans = n + 1;
        for(int node = 1;;) {
          if(T[node] >= last) break;
          if(rev[node] > 0) {
            ans = rev[node];
            break;
          }
          if(T[node + node] < last) node = node + node;
          else node = node + node + 1;
        }
        if(ans > to) break;
        inds.push_back(ans);
        last = t[ans];
        del(ans);
      }
 
 
      reverse(inds.begin(), inds.end());
      for(int x : inds) toqueue(x);
 
      inqueue.erase(x);
 
      int to = (inqueue.empty() ? n : *inqueue.begin() - 1);
      int ans = n + 1;
      for(int node = 1;;) {
        if(T[node] > timing) break;
        if(rev[node] > 0) {
          ans = rev[node];
          break;
        }
        if(T[node + node] <= timing) node = node + node;
        else node = node + node + 1;
      }
      if(ans <= to) toqueue(ans);
    }
 
 
    if(qu.empty()) {
      while(it < people.size() && done[people[it].second] == 1) {
        ++it;
      }
      if(it == people.size()) break;
      timing = people[it].first;
      toqueue(people[it].second);
      ++it;
      continue;
    }
  }
 
 
  for(int i = 1; i <= n; ++i) cout << res[i] << " ";
  cout << endl;
 
  return 0;
}