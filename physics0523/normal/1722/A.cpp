// The statement and sample was so bad
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string base="Timur";
  sort(base.begin(),base.end());
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    sort(s.begin(),s.end());
    if(s==base){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}