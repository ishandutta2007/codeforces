#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 50;
int n, a[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  if (a[0] == a[n / 2])
    puts("Bob");
  else
    puts("Alice");
}