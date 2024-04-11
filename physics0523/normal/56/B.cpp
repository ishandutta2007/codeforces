#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n+1);
  for(int i=1;i<=n;i++){cin >> p[i];}
  int l=-1,r=-1;
  for(int i=1;i<=n;i++){
    if(p[i]!=i){l=i;break;}
  }
  for(int i=n;i>=1;i--){
    if(p[i]!=i){r=i;break;}
  }
  if(l==-1){cout << "0 0\n";return 0;}
  vector<int> jud={0};
  for(int i=1;i<l;i++){
    jud.push_back(p[i]);
  }
  for(int i=r;i>=l;i--){
    jud.push_back(p[i]);
  }
  for(int i=r+1;i<=n;i++){
    jud.push_back(p[i]);
  }
  bool isok=true;
  for(int i=1;i<=n;i++){
    if(jud[i]!=i){isok=false;}
  }
  if(isok){cout << l << ' ' << r << '\n';}
  else{cout << "0 0\n";}
  return 0;
}