#include <bits/stdc++.h>

using namespace std;

int n, k, last_asked;

int ask(int x) {
  x = (x % n + n) % n;
  cout << "? " << x + 1 << endl;
  int val; cin >> val;
  return last_asked = val;
}

void guess(int x) {
  x = (x % n + n) % n;
  cout << "! " << x + 1 << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> k;
  if (n <= 10) {
    for(int i = 0; i < 30 + n; ++i) ask(0);
    for(int i = 0; i < n; ++i) {
      if (ask(i) > k && ask(i-1) <= k) {
        guess(i-1);
      }
    }
  }

  int m = sqrt(n) - 1;
  for(int i = 0; i < m; ++i) ask(0);

  int pos = 0;
  while(true) {
    int val = ask(pos);
    if (val == k) {
      pos += m;
      continue;
    }
    break;
  }
  
  if (last_asked < k) {
    if(ask(pos + m) <= k) pos += m;
    for(int i = 0; i < m + 5; ++i) {
      if(ask(pos + i) > k) guess(pos+i-1);
    }
  }
  else {
    if(ask(pos - m) >= k) pos -= m;
    for(int i = 0; i < m + 5; ++i) {
      if(ask(pos - i) < k) guess(pos-i+1);
    }
  }

  return 0;
}