#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}

  int res=0;
  vector<pair<int,int>> dp;
  for(int i=0;i<n;i++){
    vector<pair<int,int>> ndp;
    int fl=1;

    for(auto nx : dp){
      pair<int,int> adq=nx;
      if(adq.second==a[i]){
        fl=0;
        adq.first++;
        ndp.push_back(adq);
      }
      else{
        adq.first--;
        if(adq.first!=0){ndp.push_back(adq);}
      }
    }
    if(fl==1){
      ndp.push_back(make_pair(1,a[i]));
    }

    sort(ndp.begin(),ndp.end(),greater<pair<int,int>>());

    if(ndp[0].first==3){
      continue;
    }
    else{
      res++;
      dp.swap(ndp);
    }
  }
  cout << res << '\n';
  return 0;
}