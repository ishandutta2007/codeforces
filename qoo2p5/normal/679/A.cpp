#include <bits/stdc++.h>

using namespace std;

const int N = 101;

bool p[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
  
  fill(p, p + N, true);
  
  for (int i = 2; i < N; i++) {
    if (!p[i]) continue;
    for (int j = i * i; j < N; j += i) p[j] = false;
  }
  
  int cnt = 0;
  int d = -1;
  
  for (int i = 2; i <= 10; i++) {
    if (!p[i]) continue;
    cout << i << endl;
    string s;
    cin >> s;
    if (s[0] == 'y') {
      cnt++;
      d = i;
      break;
    }
  }
  
  if (d == -1) {
    cout << "prime" << endl;
    return 0;
  }
  
  {
    cout << d * d << endl;
    string s;
    cin >> s;
    if (s[0] == 'y') {
      cout << "composite" << endl;
      return 0;
    }
  }
  
  for (int i = d + 1; i * d <= 100; i++) {
    if (!p[i]) continue;
    cout << i << endl;
    string s;
    cin >> s;
    if (s[0] == 'y') {
      cnt++;
    }
  }
  
  if (cnt >= 2) {
    cout << "composite" << endl;
  } else {
    cout << "prime" << endl;
  }

	return 0;
}