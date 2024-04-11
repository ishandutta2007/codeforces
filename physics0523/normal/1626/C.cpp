#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> k(n),h(n);
    for(auto &nx : k){cin >> nx;}
    for(auto &nx : h){cin >> nx;}
    stack<pl> st;
    st.push({k[0],h[0]});
    for(int i=1;i<n;i++){
      pl cd={k[i],h[i]};
      while(1){
        if(st.empty()){
          st.push(cd);
          break;
        }
        pl stt=st.top();
        long long d=cd.first-stt.first;
        if(d>=cd.second){st.push(cd);break;}
        st.pop();
        cd.second=max(cd.second,stt.second+d);
      }
    }
    long long res=0;
    while(!st.empty()){
      res+=llsankaku(st.top().second);
      st.pop();
    }
    cout << res << '\n';
  }
  return 0;
}