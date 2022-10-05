#include <bits/stdc++.h>
using namespace std;
struct point{
  long double x, y, z;
  point(){
  }
  point(long double x, long double y, long double z): x(x), y(y), z(z){
  }
  point operator -(point P){
    return point(x - P.x, y - P.y, z - P.z);
  }
};
long double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y + P.z * P.z);
}
point cross(point P, point Q){
  return point(P.y * Q.z - P.z * Q.y, P.z * Q.x - P.x * Q.z, P.x * Q.y - P.y * Q.x);
}
long double area(point A, point B, point C){
  return abs(cross(B - A, C - A)) / 2;
}
struct quadratic{
  long double a, b, c;
  quadratic(): a(0), b(0), c(0){
  }
  quadratic(long double a, long double b, long double c): a(a), b(b), c(c){
  }
  quadratic operator +(quadratic f){
    return quadratic(a + f.a, b + f.b, c + f.c);
  }
  quadratic operator -(quadratic f){
    return quadratic(a - f.a, b - f.b, c - f.c);
  }
  long double value(long double x){
    return a * x * x + b * x + c;
  }
};
struct unionfind{
  vector<int> p;
  vector<quadratic> f, sum;
  unionfind(int N): p(N, -1), f(N, quadratic()), sum(N, quadratic()){
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  void update(int x, quadratic g){
    int y = root(x);
    sum[y] = sum[y] + g - f[x];
    f[x] = g;
  }
  long double get(int v, long double x){
    return sum[root(v)].value(x);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      if (p[x] < p[y]){
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
      sum[y] = sum[y] + sum[x];
    }
  }
};
int main(){
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<point> P(n);
  for (int i = 0; i < n; i++){
    int x, y, z;
    cin >> x >> y >> z;
    P[i] = point(x, y, z);
  }
  int m;
  cin >> m;
  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    c[i]--;
    if (make_pair(P[a[i]].z, a[i]) > make_pair(P[b[i]].z, b[i])){
      swap(a[i], b[i]);
    }
    if (make_pair(P[b[i]].z, b[i]) > make_pair(P[c[i]].z, c[i])){
      swap(b[i], c[i]);
    }
    if (make_pair(P[a[i]].z, a[i]) > make_pair(P[b[i]].z, b[i])){
      swap(a[i], b[i]);
    }
  }
  vector<vector<int>> F(n);
  for (int i = 0; i < m; i++){
    F[a[i]].push_back(i);
    F[b[i]].push_back(i);
    F[c[i]].push_back(i);
  }
  int q;
  cin >> q;
  vector<int> h(q), p(q);
  for (int i = 0; i < q; i++){
    cin >> h[i] >> p[i];
    p[i]--;
  }
  vector<long double> S(m);
  for (int i = 0; i < m; i++){
    S[i] = area(P[a[i]], P[b[i]], P[c[i]]);
  }
  vector<tuple<int, int, int, int>> T;
  for (int i = 0; i < q; i++){
    T.push_back(make_tuple(h[i], 2, p[i], i));
  }
  for (int i = 0; i < m; i++){
    T.push_back(make_tuple(P[a[i]].z, 1, 0, i));
    if (P[a[i]].z != P[b[i]].z){
      T.push_back(make_tuple(P[b[i]].z, 1, 1, i));
    }
    if (P[b[i]].z != P[c[i]].z){
      T.push_back(make_tuple(P[c[i]].z, 1, 2, i));
    }
  }
  for (int i = 0; i < n; i++){
    T.push_back(make_tuple(P[i].z, 0, i, -1));
  }
  sort(T.begin(), T.end(), greater<tuple<int, int, int, int>>());
  int cnt = T.size();
  unionfind UF(m);
  vector<long double> ans(q);
  vector<int> face(n);
  for (int i = 0; i < cnt; i++){
    int hc = get<0>(T[i]);
    int t = get<1>(T[i]);
    if (t == 0){
      int v = get<2>(T[i]);
      int cnt2 = F[v].size();
      for (int j = 0; j < cnt2; j++){
        int k = (j + 1) % cnt2;
        UF.unite(F[v][j], F[v][k]);
      }
      if (cnt2 != 0){
        face[v] = F[v][0];
      }
    }
    if (t == 1){
      int ph = get<2>(T[i]);
      int v = get<3>(T[i]);
      if (ph == 2){
        long double f = S[v] / (P[c[v]].z - P[a[v]].z) / (P[c[v]].z - P[b[v]].z);
        UF.update(v, quadratic(f, -2 * f * P[c[v]].z, f * P[c[v]].z * P[c[v]].z));
      }
      if (ph == 1){
        long double f = S[v] / (P[c[v]].z - P[a[v]].z) / (P[b[v]].z - P[a[v]].z);
        UF.update(v, quadratic(-f, 2 * f * P[a[v]].z, S[v] - f * P[a[v]].z * P[a[v]].z));
      }
      if (ph == 0){
        UF.update(v, quadratic(0, 0, S[v]));
      }
    }
    if (t == 2){
      int v = get<2>(T[i]);
      int id = get<3>(T[i]);
      if (hc >= P[v].z){
        ans[id] = -1;
      } else {
        ans[id] = UF.get(face[v], hc);
      }
    }
  }
  for (int i = 0; i < q; i++){
    if (ans[i] == -1){
      cout << "-1" << "\n";
    } else {
      cout << ans[i] << "\n";
    }
  }
}