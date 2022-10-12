#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    set<int> st;
    set<int> rv;
    for(int i=0;i<n;i++){rv.insert(i);}
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      st.insert(v);
      rv.erase(v);
    }
    auto it=st.end();
    it--;
    if((*it)==st.size()-1){cout << st.size()+k << '\n';continue;}
    for(int i=0;i<k;i++){
      it=rv.begin();
      int a=(*it);
      it=st.end();it--;
      int b=(*it);
      int ins=(a+b+1)/2;
      if(st.find(ins) != st.end()){break;}
      st.insert(ins);
      rv.erase(ins);
    }
    cout << st.size() << '\n';
  }
  return 0;
}