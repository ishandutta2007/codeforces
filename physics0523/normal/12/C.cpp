#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  sort(a.begin(),a.end());
  unordered_map<string,int> mp;
  for(int i=0;i<m;i++){
    string s;
    cin >> s;
    mp[s]++;
  }
  vector<int> mem;
  for(auto &nx : mp){mem.push_back(nx.second);}
  sort(mem.begin(),mem.end());
  reverse(mem.begin(),mem.end());
  int res=0;
  for(int i=0;i<mem.size();i++){res+=mem[i]*a[i];}
  cout << res << ' ';
  
  res=0;
  reverse(a.begin(),a.end());
  for(int i=0;i<mem.size();i++){res+=mem[i]*a[i];}
  cout << res << '\n';
  return 0;
}