#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int p=0,q=0;
    for(int i=0;i<3;i++){
      p+=(s[i]-'0');
    }
    for(int i=3;i<6;i++){
      q+=(s[i]-'0');
    }
    if(p==q){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}