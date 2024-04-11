#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  map<string, vector<string> > f;
  map<vector<string>, vector<string> > z;
  for (int i = 0; i < n; i++) {
    string s = "";
    int c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) {
      s += (char) c;
      c = getchar();
    }
    size_t pos = s.find("/", 7);
    if (pos == string::npos) {
      pos = s.length();
    }
    string hostname = s.substr(0, pos);
    string path = s.substr(pos);
    f[hostname].push_back(path);
  }
  for (auto &e: f) {
    auto &f = e.second;
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
    z[f].push_back(e.first);
  }
  int ac = 0;
  for (auto &e: z) {
    if (e.second.size() > 1) {
      ac++;
    }
  }
  printf("%d\n", ac);
  for (auto &e: z) {
    auto &f = e.second;
    if (f.size() > 1) {
      for (size_t i = 0; i < f.size(); i++) {
        if (i > 0) putchar(' ');
        auto &s = f[i];
        for (size_t pos = 0; pos < s.length(); pos++) {
          putchar(s[pos]);
        }
      }
      puts("");
    }
  }
}