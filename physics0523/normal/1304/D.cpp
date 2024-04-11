#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s;
    cin >> n >> s;
    Graph g(n);
    vector<int> bk(n,0);
    for(int i=0;i<(n-1);i++){
      if(s[i]=='<'){
        g[i].push_back(i+1);
        bk[i+1]++;
      }
      else{
        g[i+1].push_back(i);
        bk[i]++;
      }
    }

    {
      vector<int> cbk=bk;
      priority_queue<int> pq;
      for(int i=0;i<n;i++){
        if(cbk[i]==0){pq.push(i);}
      }
      vector<int> res(n);
      for(int i=0;i<n;i++){
        int od=pq.top();pq.pop();
        res[od]=i+1;
        for(auto &nx : g[od]){
          cbk[nx]--;
          if(cbk[nx]==0){pq.push(nx);}
        }
      }
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << res[i];
      }cout << '\n';
    }

    {
      vector<int> cbk=bk;
      priority_queue<int,vector<int>,greater<int>> pq;
      for(int i=0;i<n;i++){
        if(cbk[i]==0){pq.push(i);}
      }
      vector<int> res(n);
      for(int i=0;i<n;i++){
        int od=pq.top();pq.pop();
        res[od]=i+1;
        for(auto &nx : g[od]){
          cbk[nx]--;
          if(cbk[nx]==0){pq.push(nx);}
        }
      }
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << res[i];
      }cout << '\n';
    }
  }
  return 0;
}