#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

map < pair < int, long long >, long long > w;

int n;
long long L, each;
pair < long long, long long > ans[N];

long long ask(int id, long long x) {
  if(w[make_pair(id, x)] > 0) return w[make_pair(id, x)];
/*  if(id == 1 || id == 2) {
    if(x < 6) return 0;
    if(x > 10) return 5;
    return x - 5;
  }
  else return min(x, 5LL);*/

  cout << "? " << id << " " << x << endl;
  long long ret; cin >> ret;
  return w[make_pair(id, x)] = ret;
}

long long get(int id, long long req) {
  long long low = 0, high = 1e18, ans = high;
  while(low <= high) {
    long long mid = (low + high) >> 1;
    if(ask(id, mid) >= req) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return ans;
}

int kth(vector < int > vec, long long req, int k) {
  if(vec.size() == 1) return vec.back();
  int p = (1LL * rand() * rand() + rand()) % vec.size();
  long long at = get(vec[p], req);
  assert(vec.size());

  vector < int > s, g, e(1, vec[p]);
  for(int id : vec) if(id != vec[p]){
    long long val = ask(id, at);
    if(val < req) {
      g.push_back(id);
    }
    else if(val > req) {
      s.push_back(id);
    }
    else e.push_back(id);
  }

  if(s.size() + e.size() >= k && s.size() < k) return vec[p];
  if(k <= s.size()) return kth(s, req, k);
  return kth(g, req, k - s.size() - e.size());
}

void solve(vector < int > vec, int l, int r, long long X, long long Y) {
  if(vec.size() == 1) {
    ans[vec.back()].first = X;
    ans[vec.back()].second = Y;
    return;
  }

  int mid = vec.size() >> 1;
  long long val_mid = (l + mid - 1) * each;
  int p = kth(vec, val_mid, mid);
  long long at = get(p, val_mid);
  vector < int > s, g, e;

  for(int id : vec) {
    long long val = ask(id, at);
    if(val < val_mid) {
      g.push_back(id);
    }
    else if(val > val_mid) s.push_back(id);
    else {
      e.push_back(id);
    }
  }

  while(s.size() < mid) {
    s.push_back(e.back());
    e.pop_back();
  }

  while(e.size()) {
    g.push_back(e.back());
    e.pop_back();
  }

  solve(s, l, l + mid - 1, X, at);
  solve(g, l + mid, r, at, Y);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  srand(time(NULL));

  cin >> n >> L;
  each = L / n;

  vector < int > id;
  for(int i = 1; i <= n; ++i) id.push_back(i);
  solve(id, 1, n, 0, (long long)1e18);

  cout << "!" << endl;
  for(int i = 1; i <= n; ++i) cout << ans[i].first << " " << ans[i].second << endl;

  return 0;
}