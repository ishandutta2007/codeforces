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
    for(int i=0;i<n;i++){st.insert(i);}
    int tg;
    for(int i=30;i>=0;i--){
      if((n-1)&(1<<i)){tg=i;break;}
    }
    //cout << tg << '\n';
    int l0=((n-1)^(1<<tg)),f1=n-1;
    //cout << l0 << ' ' << f1 << '\n';
    st.erase(l0);
    st.erase(f1);
    vector<int> res;
    for(auto &nx : st){
      if((nx&(1<<tg))==0){res.push_back(nx);}
    }
    res.push_back(l0);
    res.push_back(f1);
    for(auto &nx : st){
      if((nx&(1<<tg))!=0){res.push_back(nx);}
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}