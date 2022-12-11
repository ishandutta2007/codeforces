#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int k;
  cin >> k;
  int big = 1;
  while(big <= k)
    big *= 2;
  int small = k;
  cout << 2 << " " << 3 << "\n";
  cout << (big | small) << " " << small << " " << 0 << "\n";
  cout << big << " " << (big | small) << " " << small << "\n";
  return 0;
}