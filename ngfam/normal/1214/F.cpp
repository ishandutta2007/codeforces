#include <bits/stdc++.h>

using namespace std;

const int N = 200020;
const int M = N * 2;

int n, m;
long long bit[2][M];

void upd(int id, int x, long long v) {
  x += N;
  for(; x < M; x += x & -x) bit[id][x] += v;
}

void range(int id, int x, int y, long long v) {
  upd(id, x, v);
  upd(id, y + 1, -v);
}

long long get(int id, int x) {
  x += N;
  long long ret = 0;
  for(; x; x &= x - 1) ret += bit[id][x];
  return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> m >> n;
  vector < int > a(n);
  vector < int > b(n);

  vector < pair < int, int > > points;

  for(int i = 0; i < n; ++i){
    int &x = a[i];
    cin >> x, points.emplace_back(x, i + 1);
  }
  
  for(int i = 0; i < n; ++i){
    int &x = b[i];
    cin >> x, points.emplace_back(x, -i - 1);
  }

  sort(points.begin(), points.end());
  for(int i = 0, k = points.size(); i < k; ++i) {
    points.push_back(points[i]);
  }

  vector < int > sum(n + n + n + n + n, 0);
  for(int i = 0; i < points.size(); ++i) {
    if(i == 0) sum[i] = points[i].second / abs(points[i].second);
    else sum[i] = sum[i - 1] + points[i].second / abs(points[i].second);
  }


  int pos = -1;

  long long ans = 1e18;
  for(int i = points.size() - 1; i >= 0; --i) {

    if(i + n + n < points.size()) {
      long long tot = get(0, sum[i]) + sum[i] * get(1, sum[i]);
      if(ans > tot) {
        ans = tot;
        pos = i + 1;
      }
    }
    if(i > 0){
      long long d = abs(points[i].first - points[i - 1].first);
      d = min(d, m - d);
      range(0, -n, sum[i - 1], d * sum[i - 1]);
      range(0, sum[i - 1] + 1, n, -d * sum[i - 1]);

      range(1, -n, sum[i - 1], -d);
      range(1, sum[i - 1] + 1, n, d);
    }
    
    if(i + n + n < points.size()) {
      int j = i + n + n;
      long long d = abs(points[j].first - points[j - 1].first);
      d = min(d, m - d);
      range(0, -n, sum[j - 1], -d * sum[j - 1]);
      range(0, sum[j - 1] + 1, n, d * sum[j - 1]);
      range(1, -n, sum[j - 1], d);
      range(1, sum[j - 1] + 1, n, -d);
    }


    
  }

  cout << ans << endl;

  vector < int > wait;

  vector < int > ret(n + 2);
  for(int i = pos; i < pos + n + n; ++i) {
    if(wait.empty()) {
      wait.push_back(points[i].second);
      continue;
    }
    if(points[i].second < 0) {
      if(wait.back() < 0) wait.push_back(points[i].second);
      else {
        ret[wait.back()] = points[i].second;
        wait.pop_back();
      }
    }
    else {
      if(wait.back() > 0) wait.push_back(points[i].second);
      else {
        ret[points[i].second] = wait.back();
        wait.pop_back();
      }
    }
  }

  for(int i = 1; i <= n; ++i) cout << abs(ret[i]) << " ";

  return 0;
}