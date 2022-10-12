#include<bits/stdc++.h>

using namespace std;

bool isnum(string s){
  if('0'<=s[0] && s[0]<='9'){return true;}
  return false;
}

set<string> brand={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int res=0;
  while(t>0){
    t--;
    string s;
    cin >> s;
    if(isnum(s)){
      if(stoi(s)<18){res++;}
    }
    else{
      if(brand.find(s)!=brand.end()){res++;}
    }
  }
  cout << res << '\n';
  return 0;
}