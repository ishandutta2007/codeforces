#include<bits/stdc++.h>

using namespace std;

int f(int mx,vector<int> &pf){
  int sz=pf.size();
  long long res=0;
  for(int i=0;i<(1<<sz);i++){
    int prod=1,cnt=0;
    for(int j=0;j<sz;j++){
      if(i&(1<<j)){
        prod*=pf[j];
        cnt++;
      }
    }
    if(cnt&1){res-=(mx/prod);}
    else{res+=(mx/prod);}
  }
  return ((int)res);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int maxn=1000005;
  vector<vector<int>> pf(maxn);
  for(int i=2;i<maxn;i++){
    if(!pf[i].empty()){continue;}
    for(int j=i;j<maxn;j+=i){
      pf[j].push_back(i);
    }
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    int x,p,k;
    cin >> x >> p >> k;
    int bas=f(x,pf[p]);
    int st=x+1,fi=1e9+7;
    while(st<=fi){
      int te=(st+fi)/2;
      if(f(te,pf[p])-bas >= k){fi=te-1;}
      else{st=te+1;}
    }
    cout << st << "\n";
  }
  return 0;
}