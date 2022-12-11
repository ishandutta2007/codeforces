#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100010;

double prob[N];
int n, p;

int main() {
  cin >> n >> p;
  for(int i = 0;i < n;i++) {
    int l, r;
    cin >> l >> r;
    int x = r / p - (l - 1) / p;
    prob[i] = (double) x / (double) (r - l + 1);
  }
  double ans = 0.0;
  for(int i = 0;i < n;i++) {
    int j = (i + 1) % n;
    double w = 1.0 - (1 - prob[i]) * (1 - prob[j]);
    ans += 2000.0 * w;
  }
  printf("%.10lf\n", ans);
  return 0;
}