#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair

map<pair<int,int>,int>s;

int main(){
  int n;
  cin >> n;
  int l[n],r[n];
  for(int i = 0;i<n;i++){  
    cin >> l[i] >> r[i];
  }
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++)
      s[mp(l[i]+l[j],r[i]+r[j])]++;
  }
  ll ans = 0;
  for(auto x : s)
    ans += (1LL*x.se*(x.se-1))/2;
  cout << ans << "\n";
  return 0;
}