#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pl> vp;
  for(int i=1;i<=n;i++){
    long long v;
    cin >> v;
    vp.push_back({v,i});
  }
  sort(vp.begin(),vp.end());
  long long k;
  cin >> k;
  long long cur=0,sig=0;
  for(long long i=0;i<k;i++){
    cur+=(vp[i].first*i-sig);
    sig+=vp[i].first;
  }
  long long res=cur,rid=0;
  for(long long i=1;(i+k-1)<n;i++){
    cur+=(vp[i+k-1].first*k-sig);
    sig+=vp[i+k-1].first;
    cur-=(sig-vp[i-1].first*(k+1));
    sig-=vp[i-1].first;
    if(res>cur){
      res=cur;
      rid=i;
    }
  }

  for(int i=0;i<k;i++){
    if(i){cout << ' ';}
    cout << vp[rid+i].second;
  }cout << '\n';
  return 0;
}