#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int a[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n;
  cin >> n;

  for(int i = 1; i <= n; ++i) cin >> a[i];

  int ans = n - 1;

  set < int > cur;
  for(int i = 0; i <= n; ++i) {
    if(cur.count(a[i])) break;
    cur.insert(a[i]);


    set < int > now = cur;
    for(int j = n; j >= 1; --j) {
      if(now.count(a[j])) break;
      now.insert(a[j]);
    }

    ans = min(ans, n + 1 - (int)now.size());
  }

  cout << ans;

  return 0;
}