#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  cin >> n >> m;
  string s;
  set<char>uni[m];
  ll ans = 1;
  for(int i = 0;i<n;i++){
    cin >> s;
    for(int j = 0;j<s.size();j++)
      uni[j].insert(s[j]);
  }
 
  for(int i = 0;i<m;i++){
    ans *= uni[i].size();
    ans %= 1000000007;
  }
  cout << ans << "\n";
  return 0;
}