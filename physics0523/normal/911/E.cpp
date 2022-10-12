#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> p(k);
  set<int> vst;
  for(int i=1;i<=n;i++){vst.insert(i);}
  for(auto &nx : p){
    cin >> nx;
    vst.erase(nx);
  }
  stack<int> st;
  int pt=0;
  for(int i=1;i<=n;i++){
    while(st.empty() || st.top()!=i){
      if(pt<k){
        if(pt!=0){
          if(!st.empty() && st.top()<p[pt]){cout << "-1\n";return 0;}
        }
        st.push(p[pt]);
        pt++;
      }
      else{
        int tg;
        if(st.empty()){tg=1e9;}
        else{tg=st.top();}
        auto it=vst.lower_bound(tg);
        if(it==vst.begin()){cout << "-1\n";return 0;}
        it--;
        st.push((*it));
        p.push_back((*it));
        vst.erase(it);
        pt++;
      }
    }
    st.pop();
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << p[i];
  }cout << '\n';
  return 0;
}