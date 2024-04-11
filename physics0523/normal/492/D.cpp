#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,x,y;
  cin >> n >> x >> y;
  vector<long long> vp;
  map<long long,long long> mp;

  for(long long i=1;i<=x;i++){
    mp[y*i]|=1;
    vp.push_back(y*i);
  }
  for(long long i=1;i<=y;i++){
    mp[x*i]|=2;
    vp.push_back(x*i);
  }
  sort(vp.begin(),vp.end());

  while(n>0){
    n--;
    long long v;
    cin >> v;
    v%=(x+y);
    if(v==0){v=(x+y);}
    v--;
    long long fl=mp[vp[v]];
    if(fl==1){cout << "Vanya\n";}
    if(fl==2){cout << "Vova\n";}
    if(fl==3){cout << "Both\n";}
  }
  return 0;
}