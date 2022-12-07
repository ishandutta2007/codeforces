#include <bits/stdc++.h>

using namespace std;

const int N = 20010;
const long long mod = 1e9 + 7;


multiset < int >trtrtrtr[2400000];

struct TBlock{
  long long L;
  long long R;
  int c;

  void read(){
    scanf("%d%lld%lld", &c, &L, &R); 
  }
}b[N];

struct TMatrix{
  long long a[5][5];

  TMatrix(){
    memset(a, 0, sizeof a);
  }

  TMatrix operator *(const TMatrix &other)const{
    TMatrix res;
    for(int i = 0; i < 5; ++i){
      for(int j = 0; j < 5; ++j){
        for(int k = 0; k < 5; ++k){
          res.a[i][j] += a[i][k] * other.a[k][j];
          res.a[i][j] %= mod;
        }
      }
    }
    return res;
  }
};

TMatrix binpow(TMatrix p, long long v){
  if(v == 1) return p;
  TMatrix c = binpow(p, v >> 1);
  c = (c * c);
  if(v & 1) c = (c * p);
  return c;
}

int n;
int f[N][4];
long long m;
vector < long long > points;

int main(){
  cin >> n >> m;

  points.push_back(0);
  points.push_back(1);
  points.push_back(m);
  points.push_back(m + 1);

  for(int i = 1; i <= n; ++i){
    b[i].read();
    points.push_back(b[i].L);
    points.push_back(b[i].R + 1);
  }

  sort(points.begin(), points.end());
  points.erase(unique(points.begin(), points.end()), points.end());


  for(int i = 1; i <= n; ++i){
    int l = lower_bound(points.begin(), points.end(), b[i].L) - points.begin();
    int r = lower_bound(points.begin(), points.end(), b[i].R + 1) - points.begin();
    ++f[l][b[i].c];
    --f[r][b[i].c];
  }

  TMatrix curr;
  curr.a[1][2] = 1;

  for(int i = 1; i < points.size(); ++i){
    for(int j = 1; j <= 3; ++j){
      f[i][j] += f[i - 1][j];
    }
  }


  for(int i = 1; i < points.size() - 1; ++i){
    TMatrix now; 
    for(int j = 1; j <= 3; ++j){
      if(!f[i][j]) {
        if(j > 1) now.a[j - 1][j] = 1;
        now.a[j][j] = 1;
        if(j < 3) now.a[j + 1][j] = 1;
      }
    }

    if(i > 1 || points[i + 1] > points[i] + 1) curr = (curr * binpow(now, points[i + 1] - points[i] - (i == 1)));
  }

  cout << curr.a[1][2];

	return 0;
}