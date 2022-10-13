#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res=0;
    vector<int> bk(26,1);
    for(auto &nx : s){
      res++;
      res+=bk[nx-'A'];
      bk[nx-'A']=0;
    }
    cout << res << '\n';
  }
  return 0;
}