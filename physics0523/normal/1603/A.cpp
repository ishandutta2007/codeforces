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
    vector<int> a(n+1);
    set<pair<int,int>> st;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      st.insert({i,a[i]});
    }
    while(!st.empty()){
      auto it=st.end();
      it--;
      int pt=st.size()+1;
      while(pt>=2){
        if((*it).second%pt!=0){
          st.erase(it);
          break;
        }
        pt--;
      }
      if(pt==1){break;}
      //cerr << '*' <<(*it).first << '\n';
    }
    //cout << st.size() << '\n';
    if(st.empty()){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}