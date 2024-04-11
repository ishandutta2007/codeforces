#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    multiset<string> st;
    string pre;

    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      string rs=s;
      reverse(rs.begin(),rs.end());
      if(st.find(rs)!=st.end()){
        pre+=s;
        st.erase(st.find(rs));
      }
      else{st.insert(s);}
    }
    string suf;
    for(int i=pre.size()-1;i>=0;i--){suf.push_back(pre[i]);}

    for(auto &nx : st){
      string rnx=nx;
      reverse(rnx.begin(),rnx.end());
      if(nx==rnx){
        pre+=nx;
        break;
      }
    }
    cout << ((int)pre.size())+((int)suf.size()) << '\n';
    cout << pre+suf << '\n';
  }
  return 0;
}