#include<bits/stdc++.h>

using namespace std;
using pll=pair<long long,long long>;

long long dot(pll a,pll b){
  return a.first*b.first+a.second*b.second;
}
long long cross(pll a,pll b){
  return a.first*b.second-a.second*b.first;
}
pll vec(pll a,pll b){
  return make_pair(b.first-a.first , b.second-a.second);
}

void getpt(pll &x){
  cin >> x.first >> x.second;
}

int main(){
  vector<pll> a(3);
  getpt(a[0]);
  getpt(a[1]);
  getpt(a[2]);
  int res=3;
  if(a[0].first == a[1].first && a[1].first == a[2].first){cout << "1\n";return 0;}
  if(a[0].second == a[1].second && a[1].second == a[2].second){cout << "1\n";return 0;}
  sort(a.begin(),a.end());
  for(int i=0;i<6;i++){
    if(i){next_permutation(a.begin(),a.end());}
    if(a[0].first==a[1].first){
      int st=min(a[0].second,a[1].second);
      int fi=max(a[0].second,a[1].second);
      if(a[2].second<=st || fi<=a[2].second){cout << "2\n";return 0;}
    }
    if(a[0].second==a[1].second){
      int st=min(a[0].first,a[1].first);
      int fi=max(a[0].first,a[1].first);
      if(a[2].first<=st || fi<=a[2].first){cout << "2\n";return 0;}
    }
  }
  cout << res << '\n';
  return 0;
}