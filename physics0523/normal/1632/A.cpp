#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    cin >> l;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if(s=="0" || s=="1" || s=="01"){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}