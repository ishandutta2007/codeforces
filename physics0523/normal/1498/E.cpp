#include<bits/stdc++.h>

using namespace std;

bool ask(int u,int v){
  cout << "? " << u << ' ' << v << '\n';
  fflush(stdout);
  string s;
  cin >> s;
  if(s=="Yes"){return true;}
  return false;
}

void ans(int u,int v){
  cout << "! " << u << ' ' << v << '\n';
  fflush(stdout);
}

using pi=pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> k(n+1);
  vector<int> bk(n,0);
  for(int i=1;i<=n;i++){
    cin >> k[i];
    bk[k[i]]++;
  }
  for(int i=0;i<n;i++){
    if(bk[i]==0){break;}
    if(i==n-1){
      ans(0,0);
      return 0;
    }
  }
  vector<pi> vp;
  for(int i=1;i<=n;i++){
    vp.push_back({k[i],i});
  }
  sort(vp.begin(),vp.end());
  vector<pair<int,pi>> vpip;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      vpip.push_back({abs(vp[i].first-vp[j].first),{vp[j].second,vp[i].second}});
    }
  }
  sort(vpip.begin(),vpip.end());
  reverse(vpip.begin(),vpip.end());
  for(auto &nx : vpip){
    pi cp=nx.second;
    if(ask(cp.first,cp.second)){
      ans(cp.first,cp.second);
      return 0;
    }
  }
  ans(0,0);
  return 0;
}