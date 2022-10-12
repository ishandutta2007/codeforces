#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s,t;
    cin >> s >> t;
    if(t=="abc"){
      int bc=0,cc=0;
      vector<int> bk(26,0);
      for(auto &nx : s){
        bk[nx-'a']++;
      }
      for(int i=0;i<26;i++){
        int j=i;
        if(bk[0]>0){
          if(i==1){j=2;}
          if(i==2){j=1;}
        }
        for(int ml=0;ml<bk[j];ml++){cout << (char)('a'+j);}
      }cout << '\n';
    }
    else{
      sort(s.begin(),s.end());
      cout << s << '\n';
    }
  }
  return 0;
}