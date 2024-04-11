#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int cnt[N];
int fuck[N];
int nani[N];
vector < int > ofcount[N];
vector < pair < int, int > > w[200];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string s; cin >> s;
  int magic = min((int)s.size(), 1500);

  int n = s.size();
  s = " " + s;

  vector < int > pos;
  for(int i = 1; i <= n; ++i) {
    cnt[i] = cnt[i - 1] + (s[i] == '1');
    if(s[i] == '1') pos.push_back(i);
  }

  long long answer = 0;
  for(int len = 1; len <= magic; ++len) {
    for(int i = 1; i <= n; ++i) nani[i] = (i - 1) % len;
    for(int i = 0; i + len - 1 < pos.size(); ++i) {
      int posx = pos[i], posy = pos[i + len - 1];
      int pre = (i > 0 ? pos[i - 1] + 1 : 1);
      int nxt = (i + len < pos.size() ? pos[i + len] - 1 : n);
      for(int j = pre; j <= posx; ++j) ++fuck[nani[j]];
      for(int j = posy; j <= nxt; ++j) answer += fuck[j % len];
      for(int j = pre; j <= posx; ++j) --fuck[nani[j]];
    }
  }

  for(int i = 0; i <= n; ++i) {
    ofcount[cnt[i]].push_back(i);
  }

  int bound = 135;
  for(int i = 0; i <= n; ++i) {
    for(int p : ofcount[i]) {
      for(int t = 0; t <= bound; ++t) {
        w[t].emplace_back(p - cnt[p] * t, i);
      }
    }
  }

  for(int t = 0; t <= bound; ++t) {
    sort(w[t].begin(), w[t].end());
    int ptr = 0, curcount = 0;
    for(int i = 0; i < w[t].size(); ++i) {
      if(i > 0 && w[t][i].first != w[t][i - 1].first) {
        ptr = i;
        curcount = 0;
      }
      else {
        while(w[t][ptr].second <= w[t][i].second - magic - 1) {
          ++curcount;
          ++ptr;
        }
      }
      answer += curcount;
    }
  }

  cout << answer << endl;

  return 0;
}