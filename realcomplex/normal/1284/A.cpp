#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  int n, m;
  cin >> n >> m;
  string t[n], s[m];
  for(int i = 0 ; i < n ; i ++ )
    cin >> t[i];
  for(int i = 0 ; i < m ; i ++ )
    cin >> s[i];
  vector<string> y;
  for(int i = 0 ; i < n * m ; i ++ )
    y.push_back(t[i%n] + s[i%m]);
  int q;
  cin >> q;
  int id;
  for(int i = 0 ; i < q; i ++ ){
    cin >> id;
    id--;
    cout << y[id % y.size()] << "\n";
  }
  return 0;
}