#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;

    Graph g(n);
    for(int i=1;i<n;i++){
      int p;
      cin >> p;
      p--;
      g[p].push_back(i);
    }
    vector<long long> l(n),r(n);
    for(int i=0;i<n;i++){cin >> l[i] >> r[i];}

    int res=0;
    for(int i=n-1;i>=0;i--){
      if(g[i].size()==0){res++;continue;}
      long long mxm=0;
      for(auto &nx : g[i]){
        mxm+=r[nx];
      }
      // cout << i << ':' << l[i] << ' ' << mxm << '\n';
      if(l[i]<=mxm){r[i]=min(r[i],mxm);}
      else{res++;}
    }
    cout << res << '\n';
  }
  return 0;
}