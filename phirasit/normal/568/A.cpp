#include <iostream>

using namespace std;

const int LIMIT = 1500010;
int p, q;

int isprime(int x) {
  if(x == 1) return false;
  for(int i = 2;i * i <= x;i++) { 
    if(x % i == 0) {
      return false;
    }
  }
  return true;
}
int ispalin(int x) {
  int k = 1, kk = 1;
  while(10 * kk <= x) kk *= 10;
  while(k < kk) {
    if((x / k) % 10 != (x / kk) % 10) {
      return false;
    }
    k *= 10;
    kk /= 10;
  }
  return true;
}
int main() {
  cin >> p >> q;
  int ans = -1;
  int p1 = 0, p2 = 0;
  for(int i = 1;i < LIMIT;i++) {
    p1 += isprime(i);
    p2 += ispalin(i);
    if(p1 * q <= p2 * p) {
      ans = i;
    }
  }
  if(ans == -1) {
    cout << "Palindromic tree is better than splay tree" << endl;
  }else {
    cout << ans << endl;
  }
  return 0;
}