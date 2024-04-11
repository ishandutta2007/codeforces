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
    if(s.size()%2==0){
      cout << "Alice ";
      int res=0;
      for(auto &nx : s){res+=(nx-'a'+1);}
      cout << res << '\n';
    }
    else{
      int sum=0;
      for(auto &nx : s){sum+=(nx-'a'+1);}
      int ap=sum-min(s[0]-'a'+1,s[s.size()-1]-'a'+1);
      int bp=sum-ap;
      if(ap>=bp){
        cout << "Alice " << ap-bp << '\n';
      }
      else{
        cout << "Bob " << bp-ap << '\n';
      }
    }
  }
  return 0;
}