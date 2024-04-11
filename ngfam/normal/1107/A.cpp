#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int T; cin >> T;

  while(T--) {
    int n; string s;
    cin >> n >> s;

    if(n == 2 && s[0] >= s[1]) {
      cout << "NO" << endl;
      continue;
    } 

    cout << "YES" << endl;
    cout << 2 << endl;

    cout << s[0] << " ";
    for(int i = 1; i < n; ++i) cout << s[i];
    cout << endl;
  }

	
  return 0;
}