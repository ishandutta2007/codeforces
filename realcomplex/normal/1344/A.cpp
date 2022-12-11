#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n;
  cin >> n;
  set<int> nums;
  int x;
  for(int i = 0; i <n ; i ++ ){
    cin >> x;
    x %= n;
    nums.insert((x + i + n) % n);
  }
  if(nums.size() == n)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    solve();
  }
  return 0;
}