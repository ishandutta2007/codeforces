#include <bits/stdc++.h>

using namespace std;

int tot[27];
int cnt[27];
int str[5050][27][27];


int main(){

  string s;
  cin >> s;

  for(char c : s){
    ++tot[c - 'a'];
  }

  int n = s.size();
  s += s;




  for(int i = 0; i < n; ++i){
    for(int j = 1; j < n; ++j){
      ++str[j][s[i] - 'a'][s[i + j] - 'a'];
    }
  }
	
  double ans = 0;


  set < char > done;

  int len = 0;

  for(char c : s){
    if(done.count(c)) continue;
    done.insert(c);

    double mx = -1;

    for(int i = 0; i < n; ++i){
      int tot = 0, len = 0;
      for(int o = 0; o < 26; ++o){
        len += str[i][c - 'a'][o];
        if(str[i][c - 'a'][o] == 1) ++tot;
      }
      mx = max(mx, double(tot) / len);
    }

    if(mx == -1) continue;

    ans += double(tot[c - 'a'] * mx) / double(n);
  } 

  cout << fixed << setprecision(7) << double(ans);

	return 0;
}