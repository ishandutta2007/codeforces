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
    int n,k;
    cin >> n >> k;
    set<int> st;
    for(int i=1;i<=2*n;i++){st.insert(i);}
    vector<pi> pv(n);
    for(int i=0;i<k;i++){
      cin >> pv[i].first >> pv[i].second;
      if(pv[i].first>pv[i].second){swap(pv[i].first,pv[i].second);}
      st.erase(pv[i].first);
      st.erase(pv[i].second);
    }
    for(int i=k;i<n;i++){
      int cv=(*st.begin());
      pv[i].first=cv;
      st.erase(cv);
    }
    for(int i=k;i<n;i++){
      int cv=(*st.begin());
      pv[i].second=cv;
      st.erase(cv);
    }
    // for(int i=0;i<n;i++){
    //   cout << pv[i].first << ',' << pv[i].second << '\n';
    // }
    int res=0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        vector<int> cv={pv[i].first,pv[i].second,pv[j].first,pv[j].second};
        sort(cv.begin(),cv.end());
        if(cv[0]==pv[i].first && cv[2]==pv[i].second){
          //cout << i << ' ' << j << '\n';
          res++;
        }
        if(cv[1]==pv[i].first && cv[3]==pv[i].second){
          //cout << i << ' ' << j << '\n';
          res++;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}