#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int mxm=620000;

long long solve(vector<pi> &pv){
  long long res=0;
  multiset<int> fr,bk;
  vector<vector<int>> mem(mxm);
  for(auto &nx : pv){
    mem[nx.first].push_back(nx.second);
    bk.insert(nx.second);
  }
  for(int i=0;i<mxm;i++){
    if(i%2==0){
      for(auto &nx : mem[i]){
        bk.erase(bk.find(nx));
        fr.insert(nx);
      }
    }
    else{
      if(fr.size()>=2 && bk.size()>=2){
        int l=max(*fr.begin(),*bk.begin());
        l++;
        int r=min(*fr.rbegin(),*bk.rbegin());
        r--;
        if(l<=r){
          res+=(r-l)/2;
          res++;
        }
      }
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi> od,ev;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    x+=300000;
    y+=100000;
    if((x+y)%2==0){ev.push_back({x+y,x-y});}
    else{od.push_back({x+y+1,x-y+1});}
  }
  long long res=0;
  res+=solve(ev);
  res+=solve(od);
  cout << res << "\n";
  return 0;
}