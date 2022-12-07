#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  long long k;
  int n; cin >> n >> k;
  vector<int> a(n);
  for(int &x : a) cin >> x;

  map<long long, int> kuroni;
  for(int &x : a) ++kuroni[x];

  while(k > 0) {
    auto p = kuroni.begin();
    auto q = kuroni.end();
    --q;
    if(p == q) break;

    auto w = p, h = q;
    ++w; --h;

    if(k < min(p -> second, q -> second)) break;

    if(p -> second < q -> second) {
      long long dist = w -> first - p -> first;
      long long go = min(dist, k / p ->second);

      k -= go * p -> second;

      long long save2 = p -> second;

      if(go == dist) {
        long long save = w -> first;
        kuroni[save] += save2;
        kuroni.erase(p);
      }
      else {
        long long save = p -> first + go;
        kuroni[save] += save2;
        kuroni.erase(p);
      }
    }
    else {
      long long dist = q -> first - h -> first;
      long long go = min(dist, k / q ->second);
      long long save2 = q -> second;

      k -= go * q -> second;
      if(go == dist) {
        long long save = h -> first;
        kuroni[save] += save2;
        kuroni.erase(q);
      }
      else {
        long long save = q -> first - go;
        kuroni[save] += save2;
        kuroni.erase(q);
      }
    }
  }

  cout << (kuroni.rbegin() -> first - kuroni.begin() -> first) << endl;

  return 0;
}