#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  for(int i=0;i<n;i++){
    if(a[i]>(i+1)){cout << "-1\n";return 0;}
  }

  set<int> st;
  for(int i=0;i<=n+5;i++){st.insert(i);}
  for(int i=0;i<n;i++){st.erase(a[i]);}

  vector<int> b(n,-1);

  if(a[0]==1){b[0]=0;st.erase(0);}
  for(int i=1;i<n;i++){
    if(a[i-1]<a[i]){
      b[i]=a[i-1];
      st.erase(b[i]);
    }
  }
  for(int i=0;i<n;i++){
    if(b[i]==-1){
      auto it=st.begin();
      b[i]=(*it);
      st.erase(it);
    }
  }

  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << b[i];
  }cout << '\n';
  return 0;
}