#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    string s;
    cin >> n >> k >> s;
    vector<int> bk(26,0);
    for(auto &nx : s){
      bk[nx-'a']++;
    }

    int sing=n/k;
    string res;
    for(int i=0;i<k;i++){
      for(int j=0;j<min(26,sing+1);j++){
        if(bk[j]==0 || j==sing){res.push_back('a'+j);break;}
        bk[j]--;
      }
    }
    cout << res << "\n";
  }
  return 0;
}