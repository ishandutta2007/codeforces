#include <bits/stdc++.h>

using namespace std;

const int N = 2000100;

int a[N];

int main(){

  int n; 
  cin >> n;

  int start = 1;
  for(int i = 1; i <= n; ++i) {
    a[i] = i;
  }

  for(int i = 2; i <= n; ++i) {
    vector < int > pos;
    for(int j = start; j < start + n; j += i) pos.push_back(j);
    a[start + n] = a[pos.back()];
    for(int j = int(pos.size()) - 2; j >= 0; --j) a[pos[j + 1]] = a[pos[j]];
    ++start;
  }

  for(int i = start; i < start + n; ++i) cout << a[i] << " ";

  return 0;
}