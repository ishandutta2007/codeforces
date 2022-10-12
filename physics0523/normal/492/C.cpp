#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,r,a;
  cin >> n >> r >> a;
  a*=n;
  vector<pair<long long,long long>> vp;
  for(int i=0;i<n;i++){
    long long p,q;
    cin >> p >> q;
    vp.push_back({q,p});
    a-=p;
  }
  a=max(0ll,a);
  sort(vp.begin(),vp.end());
  long long res=0;
  for(int i=0;i<n;i++){
    long long room=r-vp[i].second;
    room=min(a,room);
    res+=vp[i].first*room;
    a-=room;
  }
  cout << res << '\n';
  return 0;
}