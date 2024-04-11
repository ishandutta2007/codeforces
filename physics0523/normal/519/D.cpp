#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a(26);
  for(auto &nx : a){cin >> nx;}
  string s;
  cin >> s;
  int l=s.size();

  map<long long,long long> mp;
  long long res=0,h=0;
  for(int i=0;i<l;i++){
    res+=mp[32*h+(s[i]-'a')];
    h+=a[s[i]-'a'];
    mp[32*h+(s[i]-'a')]++;
  }
  cout << res << '\n';
  return 0;
}