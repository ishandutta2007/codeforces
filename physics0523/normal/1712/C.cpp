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
    for(auto &nx : a){cin >> nx;}
    int res=0;
    vector<int> top(n+1,1e9);
    set<int> st;
    for(int i=0;i<n;i++){
      top[a[i]]=min(top[a[i]],i);
      st.insert(a[i]);
    }
    set<int> tt;
    int tg=1e9;
    for(int i=n-1;i>=0;i--){
      if(i!=(n-1) && a[i]>a[i+1]){break;}
      tt.insert(a[i]);
      tg=min(tg,top[a[i]]);
      if(tg==i){res=max(res,(int)tt.size());}
    }
    cout << st.size()-res << "\n";
  }
  return 0;
}