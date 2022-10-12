#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a,b;
  cin >> a >> b;
  vector<pair<int,int>> pv;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    pv.push_back(make_pair(v,i));
  }
  sort(pv.begin(),pv.end());
  vector<int> fl,res(n);
  
  if(a==b){
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      if(i<a){cout << 1;}
      else{cout << 2;}
    }cout << '\n';
    return 0;
  }
  else if(a>b){
    for(int i=0;i<a;i++){fl.push_back(1);}
    for(int i=0;i<b;i++){fl.push_back(2);}
  }
  else{
    for(int i=0;i<n;i++){pv[i].second*=-1;}
    sort(pv.begin(),pv.end());
    for(int i=0;i<b;i++){fl.push_back(2);}
    for(int i=0;i<a;i++){fl.push_back(1);}
    for(int i=0;i<n;i++){pv[i].second*=-1;}
  }
  for(int i=0;i<n;i++){
    res[pv[i].second]=fl[i];
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}