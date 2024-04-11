#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

char field[50][50];

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

int p[2500];

int get(int v){
  if (p[v] == v)
    return v;
  return p[v] = get(p[v]);
}

void merge(int v, int u){
  u = get(u);
  v = get(v);
  p[u] = v;
}

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int T;
  cin >> T;
  while (T--){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j)
        cin >> field[i][j];
    }
    bool ok = true;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j){
        if (field[i][j] == 'B'){
          for (int step = 0; step < 4; ++step){
            int newx = i + x[step], newy = j + y[step];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m)
              continue;
            if (field[newx][newy] == 'G')
              ok = false;
            if (field[newx][newy] != 'B')
              field[newx][newy] = '#';
          }
        }
      }
    }
    if (!ok){
      cout << "No\n";
      continue;
    }
    for (int i = 0; i < n * m; ++i)
      p[i] = i;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j){
        for (int step = 0; step < 4; ++step){
          int newx = i + x[step], newy = j + y[step];
          if (newx < 0 || newx >= n || newy < 0 || newy >= m)
            continue;
          if (field[i][j] != '#' && field[newx][newy] != '#')
            merge(i * m + j, newx * m + newy);
        }
      }
    }
    ok = true;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j){
        if (field[i][j] == 'G'){
          if (get(i * m + j) != get(n * m - 1))
            ok = false;
        }
      }
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}