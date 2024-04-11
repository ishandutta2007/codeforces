#include<bits/stdc++.h>

using namespace std;

vector<int> pfact(int x){
  vector<int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      res.push_back(i);
      x/=i;
    }
  }
  if(x>1){res.push_back(x);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<bool> fl(3000005,true);
  int sw=-1;
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    int pv;
    if(sw!=-1){
      while(!fl[sw]){sw++;}
      pv=sw;
    }
    else{
      if(fl[a[i]]){pv=a[i];}
      else{
        for(int j=a[i]+1;;j++){
          if(fl[j]){pv=j;break;}
        }
        sw=2;
      }
    }
    cout << pv;
    vector<int> pf=pfact(pv);
    for(auto &nx : pf){
      if(fl[nx]){
        for(int j=nx;j<3000005;j+=nx){
          fl[j]=false;
        }
      }
    }
  }cout << '\n';
  return 0;
}