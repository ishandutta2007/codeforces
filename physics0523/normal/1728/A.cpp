#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<pi> vp(n);
    for(int i=1;i<=n;i++){
      cin >> vp[i-1].first;
      vp[i-1].second=i;
    }
    sort(vp.begin(),vp.end());
    cout << vp[n-1].second << "\n";
  }
  return 0;
}