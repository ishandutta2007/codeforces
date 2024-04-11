#include<bits/stdc++.h>

using namespace std;

long long f(int k,vector<int> &a){
  long long res=0;
  for(int i=0;i<a.size();i++){
    if(i%k==0){res+=a[i];}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> ps,ng;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v==0){continue;}
      if(v>0){ps.push_back(v);}
      else{ng.push_back(-v);}
    }
    sort(ps.begin(),ps.end());
    reverse(ps.begin(),ps.end());
    sort(ng.begin(),ng.end());
    reverse(ng.begin(),ng.end());
    long long res=0,dc=0;
    res+=f(k,ps);
    res+=f(k,ng);
    if(!ps.empty()){dc=max(dc,(long long)ps[0]);}
    if(!ng.empty()){dc=max(dc,(long long)ng[0]);}
    res*=2;
    res-=dc;
    cout << res << '\n';
  }
  return 0;
}