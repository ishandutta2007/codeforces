#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}

    vector<int> res(q,0);
    vector<vector<pi>> pv(n);
    for(int i=0;i<q;i++){
      int x,k;
      cin >> x >> k;
      x--;

      if(k>(n-1)){
        if(a[x]==n){res[i]+=(k-(n-1));}
        k=(n-1);
      }
      pv[k].push_back({a[x],i});
    }

    int top=a[0];
    vector<int> wc(n+1,0);
    for(int i=1;i<=n-1;i++){
      top=max(top,a[i]);
      wc[top]++;
      for(auto &nx : pv[i]){
        res[nx.second]+=wc[nx.first];
      }
    }
    for(auto &nx : res){cout << nx << "\n";}
  }
  return 0;
}