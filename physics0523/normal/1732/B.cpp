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
    string s;
    cin >> l >> s;
    int seg=1;
    for(int i=1;i<s.size();i++){
      if(s[i-1]!=s[i]){seg++;}
    }
    if(s[0]=='0'){
      // 0101...
      cout << max(0,seg-2) << "\n";
    }
    else{
      // 1010...
      cout << max(0,seg-1) << "\n";
    }
  }
  return 0;
}