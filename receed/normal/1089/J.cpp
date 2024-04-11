#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

set<string> tok;
vector<string> order;
string ss;

void gen(int pos, int cnt) {
  if (pos == cnt) {
    if (!tok.count(ss))
      order.push_back(ss);
    return;
  }
  rep(i, 26) {
    ss[pos] = 'a' + i;
    gen(pos + 1, cnt);
  }
}
bool istok(char c) {
  return isalnum(c) || c == '_' || c == '$';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n;
  string s;
  rep(i, n) {
    cin >> s;
    tok.insert(s);
  }
  cin >> m;
  getline(cin, s);
  string a;
  rep(i, m) {
    getline(cin, s);
    size_t pos = s.find('#');
    if (pos != string::npos)
      s = s.substr(0, pos);
    if (!a.empty())
      a.push_back(' ');
    for (char c : s) {
      if (!a.empty() && c == ' ' && a.back() == ' ')
        continue;
      a.push_back(c);
    }
  }
  for (int i = 1; i <= 4; ++i) {
    ss = string(i, 'a');
    gen(0, i);
  }
  reverse(all(order));
  vector<pair<string, int>> li;
  map<string, string> mp;
  int pos = 0;
  while (pos < a.size()) {
    if (a[pos] == ' ') {
      pos++;
      continue;
    }
    string cs, mt = "";
    for (auto &i : tok)
      if (pos + i.size() <= a.size() && a.substr(pos, i.size()) == i && i.size() > mt.size())
        mt = i;
    int tpos = pos + mt.size();
    if (isdigit(a[pos])) {
      while (pos < a.size() && isdigit(a[pos]))
        cs.push_back(a[pos++]);
      if (cs.size() > mt.size())
        li.push_back({cs, 0});
      else if (cs.size() == mt.size()) {
        li.push_back({mt, 1});
        pos = tpos;
      } else {
        li.push_back({mt, -1});
        pos = tpos;
      }
    } else {
      while (pos < a.size() && istok(a[pos]))
        cs.push_back(a[pos++]);
      if (mt.size() > cs.size()) {
        li.push_back({mt, -1});
        pos = tpos;
      } else if (mt.size() == cs.size()) {
        li.push_back({mt, 3});
        pos = tpos;
      }
      else {
        if (!mp.count(cs)) {
          mp[cs] = order.back();
          order.pop_back();
        }
        li.push_back({mp[cs], 2});
      }
    } 
  }
  string nsp;
  vector<int> rpos(li.size()), maxp(li.size(), 1e8);
  rep(i, li.size()) {
    rpos[i] = nsp.size();
    nsp.append(li[i].first);
  }
  rep(i, li.size()) {
    int p = rpos[i];
    if ((li[i].second == 0 || li[i].second == 1) && i + 1 < li.size() && isdigit(li[i + 1].first[0]))
      maxp[i] = p + li[i].first.size();
    if ((li[i].second == 2 || li[i].second == 3) && i + 1 < li.size() && istok(li[i + 1].first[0]))
      maxp[i] = p + li[i].first.size();
    for (auto &tt : tok)
      if (tt.size() > li[i].first.size() && p + tt.size() <= nsp.size() && nsp.substr(p, tt.size()) == tt) {
        maxp[i] = min(maxp[i], p + (int) tt.size() - 1);
      }
  }
  for (int i = (int) li.size() - 2; i >= 0; i--)
    maxp[i] = min(maxp[i], maxp[i + 1]);
  int curp = 0, cmax = 1e8;
  rep(i, li.size()) {
    if (curp + (int) li[i].first.size() > cmax) {
      cout << ' ';
      cmax = 1e8;
    }
    cmax = min(cmax, maxp[i]);
    curp += li[i].first.size();
    cout << li[i].first;
  }
}