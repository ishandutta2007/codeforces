#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  vector<long long> r(n+1);
  vector<pl> vp;
  for(int i=1;i<=n;i++){
    cin >> r[i];
    vp.push_back({r[i],i});
  }
  sort(vp.begin(),vp.end());
  vector<long long> res(n+1,0);
  long long cv=0,kp=1;
  for(int i=0;i<n;i++){
    res[vp[i].second]=cv;
    if(i!=n-1){
      if(vp[i].first==vp[i+1].first){kp++;}
      else{cv+=kp;kp=1;}
    }
  }
  for(int i=0;i<k;i++){
    int u,v;
    cin >> u >> v;
    if(r[u]<r[v]){res[v]--;}
    if(r[u]>r[v]){res[u]--;}
  }
  for(int i=1;i<=n;i++){
    if(i-1){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}