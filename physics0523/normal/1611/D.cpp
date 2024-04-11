#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n+1,0),inv(n+1);
    for(int i=1;i<=n;i++){cin >> p[i];}
    for(int i=1;i<=n;i++){
      int v;
      cin >> v;
      inv[v]=i;
    }
    bool iserr=false;
    vector<int> res(n+1,0);
    for(int i=1;i<=n;i++){
      if(p[i]==i){continue;}
      if(inv[p[i]]>inv[i]){iserr=true;break;}
      res[i]=inv[i]-inv[p[i]];
    }
    if(iserr){cout << "-1\n";continue;}
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}