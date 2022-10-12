#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> bk(n);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      v--;
      bk[v]=i;
    }

    map<int,int> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      v--;
      bk[v]+=(n-i);
      bk[v]%=n;
      mp[bk[v]]++;
    }
    int res=0;
    for(auto &nx : mp){res=max(res,nx.second);}
    cout << res << '\n';
  }
  return 0;
}