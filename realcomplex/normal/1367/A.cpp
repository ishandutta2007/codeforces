#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    string b;
    cin >> b;
    cout << b[0];
    for(int i = 1; i < b.size(); i += 2)
      cout << b[i];
    cout << "\n";
  }
  return 0;
}