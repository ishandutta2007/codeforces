#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int n;
vector<int> a,inv;
vector<pi> res;
void a_swap(int x,int y){
  res.push_back({x,y});
  swap(a[x],a[y]);
  inv[a[x]]=x;
  inv[a[y]]=y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  res.clear();
  a.resize(n+1);
  inv.resize(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
    inv[a[i]]=i;
  }

  vector<bool> fl(100005,true);
  for(int i=2;i<100005;i++){
    if(!fl[i]){continue;}
    for(int j=2*i;j<100005;j+=i){fl[j]=false;}
  }
  set<int> st;
  for(int i=2;i<100005;i++){
    if(fl[i]){st.insert(i-1);}
  }
  st.insert(1e9);
  for(int i=1;i<=n;i++){
    while(inv[i]!=i){
      auto it=st.lower_bound(inv[i]-i+1);it--;
      a_swap(inv[i]-(*it),inv[i]);
    }
  }
  cout << res.size() << '\n';
  for(auto &nx : res){cout << nx.first << ' ' << nx.second << '\n';}
  return 0;
}