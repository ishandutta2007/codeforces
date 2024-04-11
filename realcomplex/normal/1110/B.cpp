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
  int n, m, k;
  cin >> n >> m >> k;
  int a;
  cin >> a;
  int b;
  vector<int> lens;
  int ans = n;
  for(int i = 1; i < n; i ++ ){
    cin >> b;
    lens.push_back(b-a-1);
    a = b;
  }
  sort(lens.begin(),lens.end());
  for(int i = 0 ; i < n - k ; i ++ ){
    ans += lens[i];
  }
  cout << ans << "\n";
  return 0;
}