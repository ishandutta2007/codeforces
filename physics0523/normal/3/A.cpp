#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,t;
  cin >> s >> t;
  int res=max(abs(s[0]-t[0]),abs(s[1]-t[1]));
  cout << res << '\n';
  while(s!=t){
    if(s[0]<t[0]){
      cout << "R";
      s[0]++;
    }
    else if(s[0]>t[0]){
      cout << "L";
      s[0]--;
    }
    if(s[1]<t[1]){
      cout << "U";
      s[1]++;
    }
    else if(s[1]>t[1]){
      cout << "D";
      s[1]--;
    }
    cout << '\n';
  }
  return 0;
}