#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

struct trie {
  trie* next[26];
  int win, lose;
  char a;
  trie() {
    for (int i = 0; i < 26; i++) {
      next[i] = NULL;
    }
    win = lose = 0;
  }

  void build(int id) {
    if (id >= s.size()) {
      return;
    }
    int pos = s[id] - 'a';
    if (next[pos] == NULL) {
      next[pos] = new trie();
      next[pos]->a = s[id];
    }
    next[pos]->build(id + 1);
  }

  void go() {
    int f = 0;
    lose = 0;
    for (int i = 0; i < 26; i++) {
      if (next[i] != NULL) {
        f = 1;
        next[i]->go();
        if (!next[i]->win) {
          win = 1;
        }
        if (!next[i]->lose) {
          lose = 1;
        }
      }
    }
    if (!f) {
      win = 0;
      lose = 1;
      return;
    }
  }
} t;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    t.build(0);
  }
  t.go();
  if (!t.win) {
    puts("Second");
    return 0;
  }
  if (t.lose) {
    puts("First");
    return 0;
  }
  if (k % 2 == 0) {
    puts("Second");
  } else {
    puts("First");
  }
  return 0;
}