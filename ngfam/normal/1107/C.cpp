#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int n, k;


  cin >> n >> k;
  string s;
  vector < int > a(n);  

  for(int &x : a) cin >> x;
  cin >> s;

  vector < int > current;
  vector < vector < pair < long long, long long > > > alphabet(26);

  for(int i = 0; i < n; ++i) {
    current.push_back(a[i]);
    if(i == n - 1 || s[i] != s[i + 1]) {
      sort(current.rbegin(), current.rend());

      long long kminus = 0, all = 0;
      for(int i = 0; i < min(int(current.size()), k); ++i) {
        kminus += current[i];
      }
      all = kminus + (current.size() >= k ? current[k - 1] : 0);
      alphabet[s[i] - 'a'].emplace_back(kminus, all);
    
      current.clear();
    }
  }

  long long ans = 0;

  for(int c = 0; c < 26; ++c) {
    long long ret = 0, current = 0;

    for(auto &p : alphabet[c]) {
      current = current + p.first;
    }

    ans += current;
  }

  cout << ans;
	
  return 0;
}