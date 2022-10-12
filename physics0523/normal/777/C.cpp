#include<bits/stdc++.h>

using namespace std;

using pi=pair<int,int>;
using query=pair<pi,int>;

int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int v;
      cin >> v;
      a[i].push_back(v);
    }
  }
  int q;
  cin >> q;
  vector<query> vq;
  for(int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    l--;r--;
    vq.push_back(make_pair(make_pair(l,r),i));
  }
  sort(vq.begin(),vq.end());
  priority_queue<pi,vector<pi>,greater<pi>> pq;
  for(int i=0;i<m;i++){
    pq.push(make_pair(-1,i));
  }
  int maxi=-1;
  vector<bool> res(q);
  for(int i=0;i<q;i++){
    //cout << vq[i].first.first << ' ';
    //cout << vq[i].first.second << ' ';
    //cout << vq[i].second << '\n';
    while(1){
      pi tg=pq.top();
      pq.pop();
      if(tg.first>=vq[i].first.first){pq.push(tg);break;}
      tg.first=vq[i].first.first;
      while(tg.first<n-1){
        //cout << tg.first << ' ' << tg.second << '\n';
        if(a[tg.first][tg.second]>a[tg.first+1][tg.second]){break;}
        tg.first++;
      }
      maxi=max(tg.first,maxi);
      pq.push(tg);
    }
    if(vq[i].first.second<=maxi){
      res[vq[i].second]=true;
    }
  }
  for(int i=0;i<q;i++){
    if(res[i]){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}