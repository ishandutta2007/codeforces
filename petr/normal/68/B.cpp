#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  scanf("%d", &n); 
  scanf("%d", &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &(a[i]));
  }
  sort(a.begin(), a.end());
  double koef = 1.0 - k / 100.0;
  double left = a[0];
  double right = a[a.size() - 1];
  while ((right - left) / right > 1e-9) {
    double middle = (left + right) / 2;
    double sum = 0;
    for (int i = 0; i < a.size(); ++i) {
      double add = a[i] - middle;
      if (add > 0) add *= koef;
      sum += add;
    }
    if (sum < 0)
      right = middle;
    else
      left = middle;
  }
  printf("%.10lf\n", (left + right) / 2);
}