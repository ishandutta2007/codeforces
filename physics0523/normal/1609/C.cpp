#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> ispl(1e6+5,true);
  ispl[0]=false;
  //ispl[1]=false;
  for(int i=2;i<1e6+5;i++){
    if(!ispl[i]){continue;}
    for(int j=2*i;j<1e6+5;j+=i){ispl[j]=false;}
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    long long res=0;
    int n,e;
    cin >> n >> e;
    vector<vector<int>> g(e);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      g[i%e].push_back(v);
    }
    for(auto &nx : g){
      long long oc=0;
      for(auto &ny : nx){
        if(ny==1){oc++;}
        else{
          if(oc>=2){res-=llsankaku(oc-1);}
          oc=0;
        }
      }
      if(oc>=2){res-=llsankaku(oc-1);}
      //cerr << res << '\n';
      int sz=nx.size();
      int st=0,ct=0;
      for(int i=0;i<sz;i++){
        if(!ispl[nx[i]]){ct=0;st=i+1;continue;}
        if(nx[i]!=1){ct++;}
        while(ct>=2){
          if(nx[st]!=1){ct--;}
          st++;
        }
        //cerr << st << ' ' << i << '\n';
        res+=(i-st);
      }
    }
    cout << res << '\n';
  }
  return 0;
}