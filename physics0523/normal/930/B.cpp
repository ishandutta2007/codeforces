#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l;
  string s;
  cin >> s;
  l=s.size();

  vector<vector<int>> mem(26);
  for(int i=0;i<l;i++){
    mem[s[i]-'a'].push_back(i);
  }

  int res=0;
  for(int i=0;i<26;i++){
    int cur=0;
    for(int j=1;j<l;j++){
      vector<int> bk(26,0);
      for(auto &nx : mem[i]){
        bk[s[(nx+j)%l]-'a']++;
      }
      int cc=0;
      for(auto &nx : bk){
        if(nx==1){cc++;}
      }
      cur=max(cur,cc);
    }
    // cout << i << " " << cur << "\n";
    res+=cur;
  }
  double rd=res;
  rd/=l;
  cout << std::setprecision(12) << rd << "\n";
  return 0;
}