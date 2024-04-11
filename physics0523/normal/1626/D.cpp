#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v]++;
    }
    set<int> st;
    int rw=0;
    st.insert(rw);
    for(auto &nx : mp){
      rw+=nx.second;
      st.insert(rw);
    }
    int res=9999999;
    vector<int> mem(3);
    for(mem[0]=0;mem[0]<20;mem[0]++){
      for(mem[1]=0;mem[1]<20;mem[1]++){
        for(mem[2]=0;mem[2]<20;mem[2]++){
          int pre=0,cres=0;
          for(int l=0;l<3;l++){
            auto it=st.upper_bound(pre+(1<<mem[l]));
            if(l==2){it=st.end();}
            it--;
            if(((1<<mem[l])-((*it)-pre))<0){cres=9999999;}
            cres+=((1<<mem[l])-((*it)-pre));
            pre=(*it);
          }
          res=min(res,cres);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}