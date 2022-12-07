#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100050;
const int magic = 200;
 
struct Hull {
    long long a[N], b[N];
    double x[N];
    int head, tail;
    Hull(): head(1), tail(0) {}
    long long get_point(long long xQuery) {
        if (head > tail) return 0;
        while (head < tail && x[head + 1] <= xQuery) head++;
        x[head] = xQuery;
        return a[head] * xQuery + b[head];
    }
    void add_line(long long aNew, long long bNew) {
        double xNew = 0;
        while (head <= tail) {
            if (aNew == a[tail]) return;
            xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
            if (head == tail || xNew >= x[tail]) break;
            tail--;
        }
        a[++tail] = aNew;
        b[tail] = bNew;
        x[tail] = xNew;
    }
    void clear() {
      head = 1;
      tail = 0;
    }
};
 
 
int n, w;
int in[N];
int wc[N];
int sum[N];
pair < int, int > a[N];
pair < long long, long long > answer[N];
Hull cht[magic + 5], q;
 
int main(){
 
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  int max_b = 0;
 
  cin >> n >> w;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].second >> a[i].first;
    ++sum[a[i].first];
    max_b = max(max_b, a[i].first);
  }
 
  for(int i = N - 2; i >= 0; --i) sum[i] += sum[i + 1];
 
  sort(a + 1, a + n + 1);
  vector < pair < int, int > > all;
 
  for(int t = 1; t <= n; t += magic) {
    for(int i = 0; i < magic + 5; ++i) cht[i].clear();
    int l = t, r = min(n, t + magic - 1);
    vector < pair < int, int > > all_b;
    for(int i = l; i <= r; ++i) all_b.emplace_back(a[i].second, i);
    sort(all_b.begin(), all_b.end());
    vector < pair < int, int > > new_all(all.size() + all_b.size());
    merge(all.begin(), all.end(), all_b.begin(), all_b.end(), new_all.begin());
    all = new_all;
 
    int cnt_old = 0, cur = 0, cnt = -1;
    vector < int > pos_b, val_b, pos_a, bigger;
    for(int i = all.size() - 1; i >= 0; --i) {
      auto p = all[i];
      if(p.second != 0) {
        pos_b.push_back(i);
        val_b.push_back(cnt_old);
        cur = 0;
        continue;
      }
 
      ++cnt_old;
      if(cur == 0) {
        ++cnt;
        pos_a.push_back(i);
        bigger.push_back(0);
      }
      ++cur;
      in[i] = cnt;
      wc[i] = cnt_old;
    }
 
    for(int i = 0; i < all.size(); ++i) {
      if(all[i].second == 0) {
        cht[in[i]].add_line(all[i].first, 1LL * all[i].first * wc[i]);
      }
    }
 
    for(int i = l; i <= r; ++i) {
      int pos;
      for(int id : pos_b) {
        if(all[id].second == i) pos = id;
      }
      for(int j = 0; j < pos_a.size(); ++j) {
        if(pos > pos_a[j]) ++bigger[j];
      }
 
      for(int j = 0; j < pos_b.size(); ++j) {
        if(pos >= pos_b[j]) ++val_b[j];
      }
 
      if(i < n && a[i + 1].first == a[i].first) continue;
 
      pair < long long, long long > best = {0LL, 0LL};
 
      for(int j = 0; j < pos_b.size(); ++j) {
        best = max(best, make_pair(1LL * val_b[j] * all[pos_b[j]].first, 1LL * all[pos_b[j]].first));
      }
 
      for(int j = 0; j < pos_a.size(); ++j) {
        cht[j].get_point(bigger[j]);
        best = max(best, make_pair(cht[j].get_point(bigger[j]), cht[j].a[cht[j].head]));
      }
      answer[a[i].first + 1] = best;
    }
 
    for(auto &p : all) p.second = 0;
  }
 
  for(int i = 1; i < N; ++i) if(answer[i].second == 0) answer[i] = answer[i - 1];
 
  cout << 0 << " " << 3 << endl;
  for(int i = 1; i <= max_b + 1; ++i) {
    cout << answer[i].first + 1LL * sum[i] * w * 1LL * i << " " << answer[i].second << "\n";
  }
 
  return 0;
}