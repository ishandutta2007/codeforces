#include<bits/stdc++.h>

using namespace std;



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  long long s, f, each;
  cin >> s >> f >> each;

  int n; cin >> n;
  vector<long long> a(n);
  for(auto &x : a) cin >> x;

  sort(a.begin(), a.end());
  vector<long long> b(n);
  if(n > 0){

    b[0] = max(s + each, a[0] + each);
    for(int i = 1; i < a.size(); ++i) {
      b[i] = max(b[i - 1] + each, a[i] + each);
    }


  }
    auto calc = [&](long long t) {
      auto fpos = upper_bound(a.begin(), a.end(), t) - a.begin();
      long long ret;
      if(fpos == 0) ret = max(t + each, s + each);
      else ret = max(t + each, b[fpos - 1] + each);
      if(ret > f) return (long long)1e18;
      return ret - t;
    };

  long long answer = calc(s);
  long long pos = s;


  for(int i = 0; i < n; ++i) {

    answer = min(answer, calc(a[i] - 1));
    if(calc(a[i] - 1) == answer) {
      pos = a[i] - 1;
    }
    answer = min(answer, calc(b[i]));
    if(calc(b[i]) == answer) {
      pos = b[i];
    }
  }

  cout << pos << endl;

  return 0;
}