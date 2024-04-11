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
    int z=-1,o=1000000007;
    for(int i=1;i<s.size();i++){
      if(s[i]==s[i-1] && s[i]=='0'){z=i;}
    }
    for(int i=s.size()-1;i>=1;i--){
      if(s[i]==s[i-1] && s[i]=='1'){o=i;}
    }
    if(o<z){cout << "No\n";}else{cout << "Yes\n";}
  }
  return 0;
}