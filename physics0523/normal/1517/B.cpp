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
    int n,m;
    cin >> n >> m;
    vector<pi> v;
    vector<vector<int>> res(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int val;
        cin >> val;
        v.push_back(make_pair(val,i));
      }
    }
    sort(v.begin(),v.end());

    int f=0;
    vector<int> pt(n,0);
    for(auto &nx: v){
      int cv=nx.first;
      int tl=nx.second;
      if(f!=m){
        res[tl][f]=cv;
        f++;
      }
      else{
        while(res[tl][pt[tl]]!=-1){pt[tl]++;}
        res[tl][pt[tl]]=cv;
      }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(j){cout << ' ';}
        cout << res[i][j];
      }cout << '\n';
    }
  }
  return 0;
}