#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<pl> vp;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      vp.push_back({a[i]+i,i});
    }
    sort(vp.begin(),vp.end());
    vector<int> jp(n+1,1);
    for(int i=0;i<(n-k);i++){jp[vp[i].second]=0;}
    long long res=0,bn=0;
    for(int i=0;i<n;i++){
      if(jp[i]==0){res+=(a[i]+bn);}
      else{bn++;}
    }
    cout << res << '\n';
  }
  return 0;
}