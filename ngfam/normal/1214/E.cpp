#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

vector < int > chain[N];
vector < int > godd[N], geven[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n; cin >> n;
  vector < pair < int, int > > d(n + 1);
  for(int i = 1; i <= n; ++i) cin >> d[i].first, d[i].second = i;

  sort(d.begin() + 1, d.end());

  int cntodd = 0;
  vector < int > odd(n + 1);

  for(int i = n; i >= 1; i--) {
    int u = d[i].second * 2 - 1, v = u + 1, w = d[i].first;
    if(cntodd > 0) geven[u].push_back(odd[cntodd]);
    odd[++cntodd] = u;

    if(cntodd + w - 1 <= n) {
      godd[cntodd + w - 1].push_back(v);
      if(chain[cntodd + w - 1].size() == 0) {
        chain[cntodd + w - 1].push_back(v);
      }
    }
    else {
      int r = cntodd + w - n;
      if(r > chain[n].size()) {
        if(chain[n].empty()) {
          assert(r == 1);
          godd[n].push_back(v);
        }
        else {
          geven[chain[n].back()].push_back(v);
        }
        chain[n].push_back(v);
      }
      else geven[chain[n][r - 2]].push_back(v);
    }
  }

  for(int i = 1; i <= 2 * n; ++i) {
    for(auto x : godd[i]) cout << odd[i] << " " << x << "\n";
    for(auto x : geven[i]) cout << i << " " << x << "\n";
  }

  return 0;
}