#include<bits/stdc++.h>

using namespace std;

int n;
vector<long long> a,b;
long long solve(vector<int> al,vector<int> bl){
  if(al.empty() && bl.empty()){return 0;}
  if(al.empty()){
    int od=bl.back();
    bl.pop_back();
    long long dlt=1e18;
    for(int i=0;i<n;i++){
      dlt=min(dlt,abs(a[i]-b[od]));
    }
    return dlt+solve(al,bl);
  }
  long long res=1e18;
  int ad=al.back();
  al.pop_back();
  for(int i=0;i<bl.size();i++){
    vector<int> nbl;
    for(int j=0;j<bl.size();j++){
      if(i!=j){nbl.push_back(bl[j]);}
    }
    res=min(res,abs(a[ad]-b[bl[i]])+solve(al,nbl));
  }
  long long dlt=1e18;
  for(int i=0;i<n;i++){
    dlt=min(dlt,abs(a[ad]-b[i]));
  }
  res=min(res,solve(al,bl)+dlt);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    cout << solve({0,n-1},{0,n-1}) << '\n';
  }
  return 0;
}