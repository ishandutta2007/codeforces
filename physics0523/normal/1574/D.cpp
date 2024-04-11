#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define MAXN 100005

using namespace std;
using piv=pair<int,vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<piv> cd;
  vector<int> na(0);
  cd.push_back(make_pair(0,na));
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    vector<int> a(k);
    for(auto &nx : a){cin >> nx;}
    priority_queue<piv,vector<piv>,greater<piv>> pq;
    for(int j=k-1;j>=0;j--){
      for(auto &nx : cd){
        piv pd=nx;
        pd.first+=a[j];
        pd.second.push_back(j+1);
        pq.push(pd);
        if(pq.size()>MAXN){
          piv od=pq.top();pq.pop();
          if(od.first==pd.first){break;}
        }
      }
    }
    cd.clear();
    while(!pq.empty()){
      cd.push_back(pq.top());
      pq.pop();
    }
    reverse(cd.begin(),cd.end());
  }
  //cout << cd.size() << '\n';
  int m;
  cin >> m;
  vector<vector<int>> st;
  for(int i=0;i<m;i++){
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    st.push_back(a);
  }
  sort(st.begin(),st.end());

  for(auto &nx : cd){
    bool isok=true;
    int p=0,q=st.size()-1,te;
    while(p<=q){
      te=(p+q)/2;
      if(st[te]==nx.second){isok=false;break;}
      if(st[te]<nx.second){p=te+1;}
      else{q=te-1;}
    }
    if(isok){
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << nx.second[i];
      }cout << '\n';
      break;
    }
  }
  return 0;
}