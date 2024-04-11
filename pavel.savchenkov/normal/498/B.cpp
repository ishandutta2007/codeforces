#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAXN 5050

const double EPS = 1e-15;

int PP[MAXN];
int TT[MAXN];

int main() {
  int N, T;
  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    cin >> PP[i] >> TT[i];
  }

  double result = 0;
  vector<double> p(T + 1, 0);
  p[0] = 1;
  for (int i = 0; i < N; i++) {
    vector<double> np(T, 0);
    for (int j = 0; j < T; j++) {
      np[j] = p[j] * PP[i] / 100.0;
      if (j > 0) np[j] += np[j - 1] * (1.0 - PP[i] / 100.0);
      if  (np[j] < EPS) np[j] = 0;
    }

    double ep = pow(1.0 - PP[i] / 100.0, TT[i] - 1);
    for (int j = T; j > 0; j--) {
      if (j >= TT[i]) {
        p[j] = np[j - 1] - np[j - TT[i]] * ep;
        p[j] += p[j - TT[i]] * ep;
      } else {
        p[j] = np[j - 1];
      }
      if  (p[j] < EPS) p[j] = 0;
      result += p[j];
    }
    p[0] = 0;
  }
  printf("%.9f\n", result);

  return 0;
}