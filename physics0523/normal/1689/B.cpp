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
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}

    if(n==1){
      cout << "-1\n";
      continue;
    }

    set<int> st;
    vector<int> res;
    for(int i=0;i<n;i++){st.insert(i+1);}
    for(int i=0;i<n-2;i++){
      auto it=st.begin();
      if((*it)==p[i]){it++;}
      res.push_back((*it));
      st.erase(it);
    }

    vector<int> suf;
    for(auto &nx : st){suf.push_back(nx);}
    do{
      bool ok=true;
      for(int i=n-2;i<n;i++){
        if(p[i]==suf[i-(n-2)]){ok=false;}
      }
      if(ok){break;}
    }while(next_permutation(suf.begin(),suf.end()));
    for(auto &nx : suf){res.push_back(nx);}

    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}