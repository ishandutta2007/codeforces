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
    int n;
    string s;
    cin >> n >> s;
    int op=-1;
    int deg=0;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){op=i;deg++;}
    }
    if(deg%2){cout << "NO\n";continue;}
    if(op==-1){cout << "NO\n";continue;}
    cout << "YES\n";

    vector<pi> pv;
    pv.push_back({(op+1)%n,(op+2)%n});
    stack<int> st;
    if(s[(op+1)%n]=='0'){st.push((op+1)%n);}
    if(s[(op+2)%n]=='0'){st.push((op+2)%n);}

    for(int dif=3;dif<=n;dif++){
      int i=(op+dif)%n;
      if(st.empty()){
        st.push((i+n-1)%n);
        pv.push_back({(i+n-1)%n,i});
      }
      else{
        int od=st.top();st.pop();
        pv.push_back({od,i});
      }
      if(s[i]=='0'){st.push(i);}
    }
    for(auto &nx : pv){
      cout << nx.first+1 << ' ' << nx.second+1 << '\n';
    }
  }
  return 0;
}