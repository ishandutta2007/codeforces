#include <bits/stdc++.h>

int T;
std::string str;

int main () {
  std::ios::sync_with_stdio (0);
  std::cin >> T;
  while (T--) {
    std::cin >> str;
    int l = 0, u = 0, d = 0;
    for (int i = 0; i < str.size (); ++i)
      if (str[i] >= 'a' && str[i] <= 'z') ++l;
      else if (str[i] >= 'A' && str[i] <= 'Z') ++u;
      else if (str[i] >= '0' && str[i] <= '9') ++d;
    if (l == 0 && u == 0) str[0] = 'a', str[1] = 'A';
    else if (u == 0 && d == 0) str[0] = 'A', str[1] = '0';
    else if (d == 0 && l == 0) str[0] = '0', str[1] = 'a';
    else if (l == 0 && u >= 2) { for (int i = 0; i < str.size (); ++i) if (str[i] >= 'A' && str[i] <= 'Z') { str[i] = 'a'; break; } }
    else if (l == 0 && d >= 2) { for (int i = 0; i < str.size (); ++i) if (str[i] >= '0' && str[i] <= '9') { str[i] = 'a'; break; } }
    else if (u == 0 && d >= 2) { for (int i = 0; i < str.size (); ++i) if (str[i] >= '0' && str[i] <= '9') { str[i] = 'A'; break; } }
    else if (u == 0 && l >= 2) { for (int i = 0; i < str.size (); ++i) if (str[i] >= 'a' && str[i] <= 'z') { str[i] = 'A'; break; } }
    else if (d == 0 && l >= 2) { for (int i = 0; i < str.size (); ++i) if (str[i] >= 'a' && str[i] <= 'z') { str[i] = '0'; break; } }
    else if (d == 0 && u >= 2) { for (int i = 0; i < str.size (); ++i) if (str[i] >= 'A' && str[i] <= 'Z') { str[i] = '0'; break; } }
    std::cout << str << "\n";
  }
}