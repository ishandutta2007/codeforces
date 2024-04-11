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
    long long k;
    cin >> n >> k;
    if(n<=61 && k>(1ll<<(n-1))){cout << "-1\n";continue;}
    k--;
    vector<int> res;
    set<int> st;
    for(int i=1;i<=n;i++){st.insert(i);}

    while(res.size()<n){
      int i=res.size();
      //cerr << i << '\n';
      int tg=n-(i+2);
      if(tg==-1){
        auto it=st.begin();
        res.push_back((*it));
        break;
      }
      int td=1;
      if(tg<=61){
        for(int j=tg;j>=0;j--){
          if(k&(1ll<<j)){td++;}
          else{break;}
        }
      }
      vector<int> mem;
      for(int j=0;j<td;j++){
        //cerr << j << '\n';
        auto it=st.begin();
        int ad=(*it);
        st.erase(ad);
        mem.push_back(ad);
      }
      reverse(mem.begin(),mem.end());
      res.insert(res.end(),mem.begin(),mem.end());
      //cerr << "ok\n";
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}