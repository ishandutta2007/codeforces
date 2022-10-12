#include<bits/stdc++.h>

using namespace std;

void divadd(int x,set<int> &st){
  for(int i=1;i*i<=x;i++){
    if(x%i){continue;}
    st.insert(i);
    st.insert(x/i);
  }
}

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
    map<int,int> mp;
    for(auto &nx : a){
      cin >> nx;
      nx+=1048576;
      mp[nx]++;
    }
    sort(a.begin(),a.end());

    bool isinf=false;
    for(auto &nx : mp){if(nx.second>=(n/2)){isinf=true;}}
    if(isinf){cout << "-1\n";continue;}

    set<int> st;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(a[i]<a[j]){divadd(a[j]-a[i],st);}
      }
    }
    int res=1;
    for(auto &nx : st){
      map<int,int> mp;
      for(int i=0;i<n;i++){mp[a[i]%nx]++;}
      for(auto &ny : mp){
        if(ny.second>=(n/2)){res=nx;}
      }
    }
    cout << res << '\n';
  }
  return 0;
}