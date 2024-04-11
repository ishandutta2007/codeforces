#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

void solve1(int n){
  if(n%2){
    cout << "NO\n";
    return;
  }
  vector<int> res(n,-1);
  for(int bc=20;bc>=1;bc--){
    int wh=(1<<bc)-1;
    for(int i=0;i<n;i++){
      int u=(i+1);
      int v=(wh^u);
      if(u>n || v>n){continue;}
      if(res[u-1]==-1 && res[v-1]==-1){
        res[u-1]=v;
        res[v-1]=u;
      }
    }
  }

  cout << "YES\n";
  for(int i=0;i<n;i++){
    if(i){cout << " ";}
    cout << res[i];
  }
  cout << "\n";
}

void solve2(int n){
  if(__builtin_popcount(n)==1){
    cout << "NO\n";
    return;
  }
  if(n<=5){
    cout << "NO\n";
    return;
  }
  if(n==6){
    cout << "YES\n";
    cout << "3 6 1 5 4 2\n";
    return;
  }

  vector<int> res={3,6,1,5,4,7,2};
  for(int bc=3;;bc++){
    int l=(1<<bc);
    int r=min(n,(1<<(bc+1))-1);
    if(l>r){break;}
    for(int i=l+1;i<=r;i++){res.push_back(i);}
    res.push_back(l);
  }

  cout << "YES\n";
  for(int i=0;i<n;i++){
    if(i){cout << " ";}
    cout << res[i];
  }
  cout << "\n";
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  solve1(n);
  solve2(n);
  return 0;
}