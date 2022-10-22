#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

tuple<string, int> name(const string &s, int i) {
  string n;
  while(isalpha(s[i])) {
    n += s[i];
    ++i;
  }
  return make_tuple(n, i);
}

tuple<int, vector<string>, int> calc(const string &s, int i) {
  string n;
  tie(n, i) = name(s, i);
  if (s[i] == '.')
    return make_tuple(0, vector<string>(1, n), i+1);
  vector<string> subords;
  int sum = 0;
  do {
    ++i;
    int cnt;
    vector<string> ss;
    tie(cnt, ss, i) = calc(s, i);
    sum += cnt;
    subords.insert(end(subords),begin(ss),end(ss));
  } while(s[i] != '.');
  sum += count(begin(subords),end(subords),n);
  subords.push_back(n);
  return make_tuple(sum, subords, i+1);
}

int main()
{
  string s;
  cin>>s;
  s += "$";
  cout << get<0>(calc(s, 0)) << endl;
  return 0;
}