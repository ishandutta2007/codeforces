#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<pi> r(n,{-1,0});
  vector<pi> c(m,{-1,0});
  for(int i=0;i<k;i++){
    int t,x,a;
    cin >> t >> x >> a;
    x--;
    if(t==1){r[x]={i,a};}
    else{c[x]={i,a};}
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(j){cout << ' ';}
      cout << max(r[i],c[j]).second;
    }cout << '\n';
  }
  return 0;
}