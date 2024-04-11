#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> k(n);
    vector<long long> c(m);
    for(int i=0;i<n;i++){
      cin >> k[i];
      k[i]--;
    }
    sort(k.begin(),k.end());
    reverse(k.begin(),k.end());
    for(int i=0;i<m;i++){
      cin >> c[i];
    }
    long long res=0;
    for(int i=0;i<n;i++){
      if(i<=k[i]){res+=c[i];}
      else{res+=c[k[i]];}
    }
    cout << res << '\n';
  }
  return 0;
}