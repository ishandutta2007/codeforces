#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const int M = 12;

int n, m;
int a[N][N];
int f[M][1 << M];
int mx[M][1 << M];
vector < int > submasks[1 << M];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  for(int mask = 0; mask < (1 << M); ++mask) {
    for(int submask = 0; submask <= mask; ++submask) {
      if((mask | submask) == mask) submasks[mask].push_back(submask);
    }
  }

  int T; cin >> T;
  while(T--) {
    cin >> n >> m;
    vector < pair < int, int > > cols;

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) cin >> a[i][j];
    }

    for(int j = 0; j < m; ++j) {
      cols.emplace_back(0, j);
      for(int i = 0; i < n; ++i){
        cols.back().first = max(cols.back().first, a[i][j]);
      }
    }

    sort(cols.rbegin(), cols.rend());
    cols.resize(min(m, n));
    
    memset(mx, 0, sizeof mx);
    memset(f, 0, sizeof f);

    for(int i = 0; i < cols.size(); ++i){
      int id = cols[i].second;
      for(int mask = 0; mask < (1 << n); ++mask) {
        for(int shift = 0; shift < n; ++shift) {
          int sum = 0;
          for(int b = 0; b < n; ++b) {
            if(mask & (1 << b)) sum += a[(b + shift) % n][id];
          }  
          mx[i][mask] = max(mx[i][mask], sum);
        }
      }
    }

    for(int i = 0; i < cols.size(); ++i) {
      for(int mask = 0; mask < (1 << n); ++mask) {
        for(int submask : submasks[mask]) {
          f[i + 1][mask] = max(f[i + 1][mask], f[i][submask] + mx[i][mask ^ submask]);
        }
      }
    }

    cout << f[cols.size()][(1 << n) - 1] << endl;
  }

  return 0;
}