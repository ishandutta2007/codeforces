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
    vector<int> bk(26,0);
    for(auto &nx : s){bk[nx-'a']++;}
    string r1,r2;
    for(int i=0;i<26;i++){
      if(bk[i]==2){r1.push_back('a'+i);}
      else if(bk[i]==1){r2.push_back('a'+i);}
    }
    cout << r1 << r1 << r2 << '\n';
  }
  return 0;
}