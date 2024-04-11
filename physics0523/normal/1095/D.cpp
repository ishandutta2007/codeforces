#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi> pv(n+1);
  for(int i=1;i<=n;i++){
    cin >> pv[i].first >> pv[i].second;
  }
  if(n==3){
    cout << "1 2 3\n";
    return 0;
  }
  int mem=1;
  cout << 1;
  for(int i=0;i<(n-1);i++){
    int a=pv[mem].first;
    int b=pv[mem].second;
    if(pv[a].first==b || pv[a].second==b){
      cout << ' ' << a;
      mem=a;
    }
    else{
      cout << ' ' << b;
      mem=b;
    }
  }cout << '\n';
  return 0;
}