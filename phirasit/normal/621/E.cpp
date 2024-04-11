#include <iostream>

using namespace std;

const long long mod = 1000000007ll;
const int D = 10;

int cnt = 0;
long long rem[1010][110];

long long digit[20];
int n, b, k, x;

int pw(int a, int b) {
  if(b == 0) return 1;
  int r = pw(a, b/2);
  r = (r * r) % x;
  if(b % 2) r = (a * r) % x;
  return r;
}
int pw(int l) {
  int id = cnt++;
  if(l == 1) {
    for(int j = 0;j <= D;j++) {
      rem[id][j % x] = (rem[id][j % x] + digit[j]) % mod;
    }
    return id;
  }
  int ls_id = pw(l / 2);
  for(int i = 0;i < x;i++) {
    for(int k = 0;k < x;k++) {
      int nw_pos = (pw(10, l / 2) * i + k) % x;
      rem[id][nw_pos] = (rem[id][nw_pos] + rem[ls_id][i] * rem[ls_id][k]) % mod;
    }
  }
  if(l % 2) {
    int nw_id = cnt++;
    for(int i = 0;i < x;i++) {
      for(int o = 0;o <= D;o++) {
        int nw_pos = (10 * i + o) % x;
        rem[nw_id][nw_pos] = (rem[nw_id][nw_pos] + rem[id][i] * digit[o]) % mod;
      }
    }
    return nw_id;
  }
  return id;
}
int main() {
  cin >> n >> b >> k >> x;
  for(int i = 0;i < n;i++) {
    int val;
    cin >> val;
    digit[val]++;
  }
  int id = pw(b);
  cout << rem[id][k] << endl;
  return 0; 
}