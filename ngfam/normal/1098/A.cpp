#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n; 
int p[N];
int s[N];
int mx[N];
int value[N];
int sumup[N];
vector < int > g[N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
  cin >> n;
  for(int i = 2; i <= n; ++i) cin >> p[i], g[p[i]].push_back(i);
  for(int i = 1; i <= n; ++i) cin >> s[i];

  for(int i = 1; i <= n; ++i) {
    if(s[i] != -1 && s[i] < mx[p[i]]) {
      cout << -1;
      return 0;
    }
    if(s[i] == -1) mx[i] = s[p[i]];
  }

  memset(value, 60, sizeof value);
  
  for(int i = n; i >= 1; --i) {
    if(s[i] != -1) value[i] = s[i];
    for(int x : g[i]) value[i] = min(value[i], value[x]);
  }


  long long ans = 0;

  for(int i = 1; i <= n; ++i) {
    if(value[i] > 1e9) value[i] = s[p[i]];
    if(s[i] != -1) ans += s[i] - s[p[i]];
    else ans += value[i] - s[p[i]], s[i] = value[i];
  }

  cout << ans << endl;

  return 0;
}