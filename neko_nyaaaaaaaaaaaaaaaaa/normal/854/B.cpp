#include <bits/stdc++.h>
using namespace std;

int main() {
      long long n, k;
      cin >> n >> k;
      long long minans, maxans;
      minans = (1 < k ? 1 : k);
      minans = (n - k == 0 ? 0 : minans);
      maxans = (n - k < 2*k ? n - k : 2*k);
      cout << minans << " " << maxans;
      
      return 0;
}