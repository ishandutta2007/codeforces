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
    vector<int> bk(128,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      v=abs(v);
      bk[v]++;
    }
    int res=min(1,bk[0]);
    for(int i=1;i<128;i++){res+=min(2,bk[i]);}
    cout << res << '\n';
  }
  return 0;
}