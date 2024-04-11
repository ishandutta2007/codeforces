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
    map<int,int> mp;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(i%2){mp[a[i]]++;}
      else{mp[a[i]]--;}
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
      if(i%2){mp[a[i]]--;}
      else{mp[a[i]]++;}
    }
    bool fl=true;
    for(auto &nx : mp){
      if(nx.second!=0){fl=false;}
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}