#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){ 
  string t;
  cin >> t;
  int p = 1;
  int s = 0;
  for(int i = t.size() - 1; i > 0 ;i -- ){
    s += (t[i] - '0') * p;
    p *= 10;
  }
  cout << s%2;
  return 0;
}