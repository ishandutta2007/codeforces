#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    string s;
    while(a>0 || b>0){
      if(a>b){
        a--;
        s.push_back('0');
      }
      else{
        b--;
        s.push_back('1');
      }
    }
    reverse(s.begin(),s.end());
    cout << s << '\n';
  }
  return 0;
}