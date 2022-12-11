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
  int tc;
  cin >> tc;
  int n;
  for(int i = 0 ;i  < tc ; i ++ ){
    cin >> n;
    vector<int> f(n);
    for(int i = 0 ; i < n; i ++ )
      cin >> f[i];
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    for(auto x : f)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}