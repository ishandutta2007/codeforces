#include <bits/stdc++.h>

using namespace std;

const int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int find(string u) {
  for (int i = 0; i < 7; i++) {
    if (days[i] == u) {
      return i;
    }
  }
  exit(1);
}

int main() {
  string u1, u2;
  cin >> u1 >> u2;
  int x = find(u1);;
  int y = find(u2);
  int z = (y - x + 7) % 7;
  for (int i = 1; i <= 11; i++) {
    if (month[i] % 7 == z) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
	return 0;
}