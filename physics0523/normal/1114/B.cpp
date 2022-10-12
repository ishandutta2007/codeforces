#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<pi> pv(n);
  for(int i=0;i<n;i++){
    cin >> pv[i].first;
    pv[i].second=i;
  }
  sort(pv.begin(),pv.end());
  reverse(pv.begin(),pv.end());
  vector<int> bk(n,0);
  long long res=0;
  for(int i=0;i<m*k;i++){
    res+=pv[i].first;
    bk[pv[i].second]=1;
  }
  cout << res << "\n";
  int cnt=0;
  bool sp=false;
  for(int i=0;i<n;i++){
    if(bk[i]==0){continue;}
    cnt++;
    if(cnt>m){
      cnt=1;
      if(sp){cout << " ";}
      sp=true;
      cout << i;
    }
  }
  cout << "\n";
  return 0;
}