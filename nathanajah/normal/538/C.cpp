#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector <pair<long long, long long> > arr;

int main() {
  scanf("%I64d %I64d", &n, &m);
  for (int i = 0; i < m; i++) {
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    arr.push_back(make_pair(a,b));
  }
  sort(arr.begin(), arr.end());
  long long maxi = max(arr[0].second + arr[0].first - 1, arr[m-1].second + n - arr[m-1].first);
  for (int i = 0; i < m - 1; i++) {
    if ((arr[i+1].first - arr[i].first  < abs(arr[i+1].second - arr[i].second))) {
      printf("IMPOSSIBLE\n");
      return 0;
    } else {
      long long deltah = arr[i+1].second - arr[i].second;
      long long deltad = arr[i+1].first - arr[i].first;
      long long sum = deltah + deltad;
      if (sum%2 == 1) {
        sum--;
      }
      maxi = max(maxi, sum/2 + arr[i].second);
    }
  }
  printf("%I64d\n", maxi);
}