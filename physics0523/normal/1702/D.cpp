#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string w;
    int p;
    cin >> w >> p;
    int sig=0;
    vector<int> bk(27,0);
    for(auto &nx : w){
      bk[nx-'a'+1]++;
      sig+=(nx-'a'+1);
    }
    for(int i=26;i>=1;i--){
      while(sig>p && bk[i]>0){
        bk[i]--;
        sig-=i;
      }
    }
    for(auto &nx : w){
      if(bk[nx-'a'+1]>0){
        bk[nx-'a'+1]--;
        cout << nx;
      }
    }cout << "\n";
  }
  return 0;
}