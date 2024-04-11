#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n, m, mm;
int pw3[N];
int a[N][3];
string name = "LMW";
vector < int > choose[3] = {{0, 1}, {0, 2}, {1, 2}};

map < pair < int, int >, pair < int, int > > f;

void print(int premask, int mask){
  {
    int temp = premask;
    for(int i = 0; i < m; ++i) {
      int c = temp % 3;
      temp /= 3;
      for(int x : choose[c]) cout << name[x];
      cout << endl;
    }
  }
  {
    int temp = mask;
    for(int i = 0; i < mm; ++i) {
      int c = temp % 3;
      temp /= 3;
      for(int x : choose[c]) cout << name[x];
      cout << endl;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  pw3[0] = 1;
  for(int i = 1; i <= n; ++i) pw3[i] = pw3[i - 1] * 3;

  m = n / 2;
  for(int mask = 0; mask < pw3[m]; ++mask) {
    int w[3] = {0, 0, 0};
    int temp = mask;
    for(int i = 0; i < m; ++i) {
      int c = temp % 3;
      temp /= 3;
      for(int x : choose[c]) w[x] += a[i][x];
    }
    pair < int, int > cur = make_pair(w[0] - w[1], w[1] - w[2]);
    if(!f.count(cur) || f[cur].second < w[0])
      f[cur] = make_pair(mask, w[0]);
  }

  int ans = -1e9;
  pair < int, int > masks = {-1, -1};

  mm = n - m;
  for(int mask = 0; mask < pw3[mm]; ++mask) {
    int w[3] = {0, 0, 0};
    int temp = mask;
    for(int i = 0; i < mm; ++i) {
      int c = temp % 3;
      temp /= 3;
      for(int x : choose[c]) w[x] += a[i + m][x];
    }

    int x = w[1] - w[0], y = w[2] - w[1];
    if(f.count(make_pair(x, y))) {
      auto p = f[make_pair(x, y)];
      if(ans > p.second + w[0]) continue;
      ans = p.second + w[0];
      masks.first = p.first;
      masks.second = mask;
    }
  }

  if(ans == -int(1e9)) cout << "Impossible";
  else print(masks.first, masks.second);
  return 0;
}