#include<bits/stdc++.h>
#define MAXN 262144

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> d(MAXN,0);
  d[0]=-1;
  d[1]=-1;
  for(int i=2;i<MAXN;i++){
    if(d[i]!=0){continue;}
    for(int j=2*i;j<MAXN;j+=i){
      d[j]=-1;
    }
  }
  for(int i=MAXN-2;i>=0;i--){
    if(d[i]==-1){d[i]=d[i+1]+1;}
  }
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m));
  for(auto &nx : a){
    for(auto &ny : nx){cin >> ny;}
  }
  int res=1e9;
  for(int i=0;i<n;i++){
    int cur=0;
    for(int j=0;j<m;j++){cur+=d[a[i][j]];}
    res=min(res,cur);
  }
  for(int j=0;j<m;j++){
    int cur=0;
    for(int i=0;i<n;i++){cur+=d[a[i][j]];}
    res=min(res,cur);
  }
  cout << res << '\n';
  return 0;
}