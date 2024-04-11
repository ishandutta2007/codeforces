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

    vector<int> u(n);
    for(auto &nx : u){cin >> nx;}
    vector<long long> s(n);
    for(auto &nx : s){cin >> nx;}
    map<int,vector<long long>> mp;
    for(int i=0;i<n;i++){mp[u[i]].push_back(s[i]);}
    vector<long long> res(n+1,0);
    for(auto &nx : mp){
      vector<long long> a=nx.second;
      sort(a.begin(),a.end());
      for(int i=1;i<a.size();i++){a[i]+=a[i-1];}
      long long st=a[a.size()-1];
      for(int i=1;i<=a.size();i++){
        long long rs=(a.size()%i);
        if(rs==0){res[i]+=st;}
        else{res[i]+=(st-a[rs-1]);}
      }
    }

    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << res[i];
    }
    cout << '\n';
  }
  return 0;
}