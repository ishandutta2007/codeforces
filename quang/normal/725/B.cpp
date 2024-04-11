#include <bits/stdc++.h>

using namespace std;

char a[1000];
string x = "xfedabc";

int main() {
  scanf("%s", a);
  long long n = atoll(a);
  char s = a[strlen(a) - 1];
  n--;
  unsigned long long res = 0;
  if (n % 4 < 2) {
    res = n / 2;
    res *= 6ll;
    if (n % 4) {
      res += 6ll;
    }
    res += n;
    res += x.find(s);
  } else {
    res = (n - 2) / 2;
    res *= 6ll;
    if (n % 4 == 3) {
      res += 6ll;
    }
    res += n - 2;
    res += x.find(s);
  }
  cout << res << endl;
  return 0;
}