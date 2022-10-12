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
    vector<long long> fl(26,0);
    vector<long long> sl(26,0);
    map<string,long long> mp;
    vector<string> s(n);
    for(int i=0;i<n;i++){
      cin >> s[i];
      fl[s[i][0]-'a']++;
      sl[s[i][1]-'a']++;
      mp[s[i]]++;
    }
    long long res=0;
    for(int i=0;i<n;i++){
      res+=fl[s[i][0]-'a'];
      res+=sl[s[i][1]-'a'];
      res-=2*mp[s[i]];
    }
    cout << (res/2) << '\n';
  }
  return 0;
}