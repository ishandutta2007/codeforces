#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, m, k; cin >> n >> m >> k;
  if(min(m, k) < n) cout << "No";
  else cout << "Yes";

  return 0;
}