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
    cin >> n;
    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<vector<int>> dis(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
      queue<int> q;
      dis[i][i]=0;
      q.push(i);
      while(!q.empty()){
        int od=q.front();q.pop();
        for(auto &nx : g[od]){
          if(dis[i][nx]>1e8){
            dis[i][nx]=dis[i][od]+1;
            q.push(nx);
          }
        }
      }
    }
    vector<int> res(n+1,1e9);
    for(int i=0;i<n;i++){
      vector<int> cres(n+1,0);
      for(int j=0;j<n;j++){
        int p=dis[0][j];
        int q=dis[i][j];
        //cout << p << ' ' << q << ',';
        if((p-q)<0){cres[0]=max(cres[0],p);}
        else{cres[p-q]=max(cres[p-q],p);}
      }
      for(int j=n-1;j>=0;j--){cres[j]=max(cres[j],cres[j+1]-1);}
      for(int j=1;j<=n;j++){cres[j]=max(cres[j],cres[j-1]);}
      for(int j=0;j<=n;j++){
        res[j]=min(res[j],cres[j]);
        //cout << cres[j] << ' ';
      }//cout << '\n';
    }
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}