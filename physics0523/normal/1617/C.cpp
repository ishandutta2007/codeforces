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
    set<int> st;
    for(int i=1;i<=n;i++){st.insert(i);}
    vector<int> rem;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(st.find(v)!=st.end()){st.erase(v);}
      else{rem.push_back(v);}
    }
    sort(rem.begin(),rem.end());
    reverse(rem.begin(),rem.end());
    int pt=0;
    bool err=false;
    for(auto &nx : rem){
      auto it=st.end();
      it--;
      int ctg=(*it);
      if(ctg>(nx-1)/2){err=true;break;}
      st.erase(it);
    }

    if(err){cout << "-1\n";}
    else{cout << rem.size() << '\n';}
  }
  return 0;
}