#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int AL = 26;
bool ok[AL];
char f[N];
int nx[N];


int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i ++ )
    cin >> f[i];
  char b;
  for(int i = 1; i <= k ; i ++ ){
    cin >> b;
    ok[b - 'a'] = true;
  }
  nx[n + 1] = n + 1;
  ll ans = 0;
  for(int i = n; i >= 1; i -- ){
    if(ok[f[i] - 'a'] == true)
      nx[i] = nx[i + 1];
    else
      nx[i] = i;
  }
  for(int i = 1; i <= n; i ++ ){
    ans += nx[i] - i;
  }
  cout << ans;
  return 0;
}