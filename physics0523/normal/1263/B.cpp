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
    vector<string> res;
    set<string> st;
    int rv=0;
    vector<string> s(n);
    vector<bool> lock(n,false);
    for(int i=0;i<n;i++){
      cin >> s[i];
      if(st.find(s[i])==st.end()){
        lock[i]=true;
        st.insert(s[i]);
      }
    }
    for(int i=0;i<n;i++){
      if(lock[i]){
        res.push_back(s[i]);
        continue;
      }
      for(int j=0;j<40;j++){
        string ms=s[i];
        int p=j/10,tg=j%10;
        ms[p]=('0'+tg);
        if(st.find(ms)==st.end()){
          st.insert(ms);
          res.push_back(ms);
          rv++;
          break;
        }
      }
    }
    cout << rv << '\n';
    for(auto &nx : res){cout << nx << '\n';}
  }
  return 0;
}