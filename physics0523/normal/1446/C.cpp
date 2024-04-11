#include<bits/stdc++.h>

using namespace std;

int rep(vector<int> v,int k){
  if(k==-1){return v.size();}
  if(v.size()==0){return 0;}
  vector<int> s0,s1;
  for(auto &nx : v){
    if(nx&(1<<k)){s1.emplace_back(nx);}
    else{s0.emplace_back(nx);}
  }
  int r0=rep(s0,k-1);
  int r1=rep(s1,k-1);
  return max(r0+min(1,r1),r1+min(1,r0));
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  cout << n-rep(v,30) << '\n';
  return 0;
}