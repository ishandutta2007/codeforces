#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  int n,m;
  cin >> n >> m;
  int sig=0;
  vector<int> a(m+1);
  for(int i=1;i<=m;i++){
    cin >> a[i];
    sig+=a[i];
  }
  if(sig<n){cout << "-1\n";return 0;}
  map<int,int> mp;
  int cnt=0;
  while(cnt<n){
    for(int j=1;j<=m;j++){
      if(a[j]==0){continue;}
      mp[j]++;
      a[j]--;cnt++;
      if(cnt==n){break;}
    }
  }
  vector<pi> pv;
  for(auto &e : mp){
    pv.push_back(make_pair(e.second,e.first));
  }
  sort(pv.begin(),pv.end());
  vector<int> res;
  for(auto &nx : pv){
    for(int i=0;i<nx.first;i++){res.push_back(nx.second);}
  }
  int p=0,q=(n+1)/2;
  vector<int> ures;
  for(int i=0;i<n;i++){
    if(i%2==0){ures.push_back(res[p]);p++;}
    else{ures.push_back(res[q]);q++;}
  }
  for(int i=0;i<n;i++){
    if(ures[i]==ures[(i+1)%n]){cout << "-1\n";return 0;}
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << ures[i];
  }cout << '\n';
  return 0;
}