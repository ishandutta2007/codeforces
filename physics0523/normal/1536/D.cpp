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
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    set<int> st;
    st.insert(-1000000007);
    st.insert(1000000007);
    st.insert(a[0]);
    bool fl=true;
    for(int i=1;i<n;i++){
      auto it=st.lower_bound(a[i-1]);
      while((*it)<=a[i-1]){it++;}
      int lg=(*it);
      it=st.lower_bound(a[i-1]);
      while((*it)>=a[i-1]){it--;}
      int sm=(*it);
      if(sm<=a[i] && a[i]<=lg){st.insert(a[i]);}
      else{fl=false;break;}
    }
    if(fl){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}