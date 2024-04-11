#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,lim;
    cin >> n >> m;
    lim=(m+1)/2;

    vector<int> res(m,-1),cnt(n),hc(m);
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    Graph g(n+m);

    for(int i=0;i<m;i++){
      int k;
      cin >> k;
      hc[i]=k;
      pq.push(make_pair(k,i));
      for(int j=0;j<k;j++){
        int h;
        cin >> h;
        h--;
        //cout << h << ' ' << n+i << '\n';
        g[h].push_back(n+i);
        g[n+i].push_back(h);
      }
    }

    bool fl=false;
    while(!pq.empty()){
      pi od=pq.top();
      pq.pop();
      int i=od.second;
      if(res[i]!=-1){continue;}
      if(od.first==0){fl=true;break;}

      //cout << od.second << '\n';
      for(auto &nx : g[n+od.second]){
        if(cnt[nx]==lim){continue;}
        if(res[i]==-1){res[i]=nx;}
        else if(cnt[nx]<cnt[res[i]]){res[i]=nx;}
      }
      if(res[i]==-1){fl=true;break;}

      cnt[res[i]]++;
      if(cnt[res[i]]==lim){
        for(auto &nx : g[res[i]]){
          hc[nx-n]--;
          pq.push(make_pair(hc[nx-n],nx-n));
        }
      }
    }
    if(fl){cout << "NO\n";continue;}
    cout << "YES\n";
    for(int i=0;i<m;i++){
      if(i){cout << ' ';}
      cout << res[i]+1;
    }cout << '\n';
  }
  return 0;
}