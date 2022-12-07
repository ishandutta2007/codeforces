#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; string s;
  cin >> n >> s;

  int cnto = 0, cntz = 0;
  for(auto &c : s) {
    if(c == 'n') ++cnto;
    else if(c == 'z') ++cntz;
  }

  for(int i = 1; i <= cnto; ++i) cout << 1 << " ";
  for(int i = 1; i <= cntz; ++i) cout << 0 << " ";

  return 0;
}