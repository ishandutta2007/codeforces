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
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    int n;
    cin >> n;
    set<int> fd;
    int x;
    for(int i = 0 ; i < n; i ++ ){
      cin >> x;
      fd.insert(x);
    }
    cout << fd.size() << "\n";
  }
  return 0;
}