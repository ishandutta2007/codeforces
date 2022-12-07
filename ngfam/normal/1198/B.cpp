#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n, q;
int a[N];
int queries[N];
int lastUpdate[N]; 

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  cin >> q;
  for(int i = 1; i <= q; ++i) {
    int t; 
    cin >> t;

    if(t == 1) {
      int p, x; cin >> p >> x;
      lastUpdate[p] = i;
      a[p] = x;
    }
    else {
      int x; cin >> x;
      queries[i] = x;
    }
  }

  for(int i = q; i >= 1; --i) {
    queries[i] = max(queries[i], queries[i + 1]);
  }

  for(int i = 1; i <= n; ++i) {
    cout << max(a[i], queries[lastUpdate[i] + 1]) << " ";
  }

  return 0;
}