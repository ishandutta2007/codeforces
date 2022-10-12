#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  map<int,pair<int,int>> mp;
  for(int sq=1;sq<=k;sq++){
    int n;
    cin >> n;
    vector<int> a(n+1);
    int sig=0;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      sig+=a[i];
    }
    set<int> st;
    for(int i=1;i<=n;i++){
      if(st.find(a[i])!=st.end()){continue;}
      st.insert(a[i]);
      if(mp[sig-a[i]].first>=1){
        cout << "YES\n";
        cout << mp[sig-a[i]].first << ' ';
        cout << mp[sig-a[i]].second << '\n';
        cout << sq << ' ';
        cout << i << '\n';
        return 0;
      }
      mp[sig-a[i]]={sq,i};
    }
  }
  cout << "NO\n";
  return 0;
}