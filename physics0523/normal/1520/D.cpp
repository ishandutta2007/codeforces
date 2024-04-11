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
    vector<int> a(n);
    map<int,long long> mp;
    for(int i=0;i<n;i++){
      cin >> a[i];
      a[i]-=i;
      mp[a[i]]++;
    }
    long long res=0;
    for(auto &nx : mp){
      res+=nx.second*(nx.second-1ll);
    }
    cout << res/2 << '\n';
  }
  return 0;
}