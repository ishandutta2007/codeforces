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
    for(auto &nx : a){cin >> nx;}
    string s;
    cin >> s;
    map<int,int> mp;
    for(int i=0;i<n;i++){
      mp[a[i]]|=(1<<(s[i]-'a'));
    }
    bool ok=true;
    for(auto &nx : mp){
      if(__builtin_popcount(nx.second)>1){ok=false;break;}
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}