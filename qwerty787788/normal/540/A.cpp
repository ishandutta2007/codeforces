#include <bits/stdc++.h>

int f(char a, char b) {
  int v1 = a - '0', v2 = b - '0';
  int dist = std::min(abs(a - b), std::min(abs(a + 10 - b), abs(a - 10 - b)));
  return dist;
} 
int main() {
  int n;
  std::string s1, s2;
  std::cin >> n >> s1 >> s2;
  int res = 0;
  for (int i = 0; i < n; i++) res += f(s1[i], s2[i]);
  std::cout << res << std::endl;
}