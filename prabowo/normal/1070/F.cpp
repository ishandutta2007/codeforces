#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> person[4];

int main() {
  scanf("%d", &n);
  
  char s[5];
  for (int i=0; i<n; i++) {
    int a;
    scanf("%s %d", s, &a);
    // cerr << s << endl;
    person[(s[0]-'0'<<1) + (s[1]-'0')].push_back(a);
  }
  
  for (int i=0; i<4; i++) sort(person[i].begin(), person[i].end(), greater<int>());
  
  int ans = 0;
  for (int p: person[3]) ans += p;
  
  if (person[1].size() < person[2].size()) swap(person[1], person[2]);
  for (int i=0; i<person[2].size(); i++) ans += person[1][i] + person[2][i];
  
  vector<int> v;
  for (int i=person[2].size(); i<person[1].size(); i++) v.push_back(person[1][i]);
  for (int i=0; i<person[0].size(); i++) v.push_back(person[0][i]);
  sort(v.begin(), v.end(), greater<int>());
  
  for (int i=0; i<min(v.size(), person[3].size()); i++) ans += v[i];
  
  printf("%d\n", ans);
  return 0;
}