#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> n1 = {mp(1, 1), mp(1, 2), mp(2, 1), mp(2, 2)};
  int k = 3;
  for(int i = 0 ; i < n; i ++ ){
    n1.push_back(mp(k, k));
    n1.push_back(mp(k - 1, k));
    n1.push_back(mp(k, k-1));
    k ++ ;
  }
  cout << n1.size() << "\n";
  for(auto x : n1)
    cout << x.fi << " " << x.se << "\n";
  return 0;
}