#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

int N;
int isPrime[MAXN];
int fact[MAXN];
vector<int> primes;

int in[MAXN];
vector<int> order;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;

  for (int i = 1; i < N + 1; i++) {
    isPrime[i] = 1;
    fact[i] = i;
  }

  isPrime[1] = fact[1] = 1;
  primes.emplace_back(1);
  for (int i = 2; i < N + 1; i++) {
    if (isPrime[i]) {
      primes.emplace_back(i);
      fact[i] = i;
      for (int j = i + i; j < N + 1; j += i) {
        fact[j] = min(fact[j], i);
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    order.emplace_back(i);
  }

  sort(begin(order), end(order), [&](int a, int b) {
    return a / fact[a] < b / fact[b];
  });

  for (int i = 1; i < N; i++) {
    cout << (order[i] / fact[order[i]]) << " \n"[i == N - 1];
  }
}