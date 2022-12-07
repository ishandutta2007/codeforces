#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5015;
const int N = MAXN + MAXN;


int n;
int p[MAXN];

struct num{
  int b[MAXN];
  int isPar(const num &rhs) const{
    int ans = 1;
    for(int j = 0; j < MAXN; ++j) {
      if(rhs.b[j] < b[j]) return 0;
      if(b[j] < rhs.b[j]) ans = 2;
    }
    return ans;
  };
  int dist(const num &rhs) const{
    int ans = 0;
    for(int j = 0; j < MAXN; ++j) {
      ans += rhs.b[j] - b[j];
    }
    return ans;
  }

  void write() {
    for(int i = 0; i < 20; ++i) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}num[N];

int a[N];
int id[MAXN];
int countnode;
vector<pair<int, int>> g[N];
pair<int, int> par[N];

vector<int> st;

void push(int v){
  if(v == 0) {
    st.push_back(v);
    return;
  }
  while(!st.empty()) {
    int x = st.back();
    int cmp = num[x].isPar(num[v]);
    if(!cmp) {
      par[x] = min(par[x], make_pair(num[v].dist(num[x]), v));
      st.pop_back();
    }
    else {
      par[v] = min(par[v], make_pair(num[x].dist(num[v]), x));
      break;
    }
  }
  st.push_back(v);
}

long long start = 0;

void dfs_prepare(int x) {
  for(auto p : g[x]) {
    dfs_prepare(p.first);
    a[x] += a[p.first];
    start += 1LL * a[p.first] * p.second;
  }
}

long long ans = 1e18;

void dfs_solve(int x, long long cur) {
  ans = min(ans, cur);

  for(auto p : g[x]) {
    int low = 1, high = p.second - 1, risan = low;
    auto f = [&](int x) {
      return cur - 1LL * p.second * (2 * a[p.first] - n);
    };
    while(low <= high) {
      int mid = (low + high) >> 1;
      ans = min(ans, f(mid));
      if(f(mid) >= f(mid - 1)){
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    dfs_solve(p.first, f(p.second));
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for(int i = 2; i < MAXN; ++i) {
    if(!p[i]) {
      for(int j = i; j < MAXN; j += i) {
        p[j] = i;
      }
    }
  }

  push(0);
  memset(par, 60, sizeof par);

  for(int i = 1; i + 1 < MAXN; ++i) {
    id[i + 1] = ++countnode;
    for(int j = 0; j < MAXN; ++j) {
      num[countnode].b[j] = num[id[i]].b[j];
    }

    int temp = i + 1;
    while(temp > 1) {
      ++num[countnode].b[p[temp]];
      temp /= p[temp];
    }

    /// need cannot be <= 1
    int need = p[i + 1];

    ++countnode;
    for(int j = need; j < MAXN; ++j) {
      num[countnode].b[j] = num[id[i]].b[j];
    }
    push(countnode);
    push(countnode - 1);
  }

  for(int i = 1; i <= countnode; ++i) {
    g[par[i].second].emplace_back(i, par[i].first);
  }

  cin >> n;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++a[id[x]];
  }
  dfs_prepare(0);
  dfs_solve(0, start);


  cout << ans << endl;
//  cout << start << endl;

  return 0;
}