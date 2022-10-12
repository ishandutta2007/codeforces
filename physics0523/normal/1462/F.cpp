#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<pair<int,int>> pv;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
      int a,b;
      cin >> a >> b;
      pv.push_back(make_pair(a,-i));
      pv.push_back(make_pair(b,i));
    }
    sort(pv.begin(),pv.end());
    int res=n;
    vector<int> calc(n+1,0);
    int sp=n,fp=0;
    for(auto &nx:pv){
      if(nx.second<0){
        sp--;
        calc[-nx.second]+=fp;
      }
      else{
        fp++;
        calc[nx.second]+=sp;
      }
    }
    for(int i=1;i<=n;i++){
      res=min(calc[i],res);
    }
    cout << res << '\n';
  }
}