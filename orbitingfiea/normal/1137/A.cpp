#include<bits/stdc++.h>
#define ll long long
#define se second
using namespace std;

int n, m, a[1010][1010], b[1010][1010], c[1010][1010], ans[1010][1010];

map<int,vector<int> >mp;

int main(){
  cin>>n>>m;
  for (int i=1;i<=n;++i){
    for (int j=1;j<=m;++j){
      scanf("%d",&a[i][j]);
    }
  }
  for (int j=1;j<=m;++j){
    mp.clear();
    for (int i=1;i<=n;++i)
      mp[a[i][j]].push_back(i);
    int l=0, r=mp.size();
    for (auto &it:mp){
      r--;
      for (auto o:it.se)
        b[o][j]=l, c[o][j]=r;
      l++;
    }
  }
  for (int i=1;i<=n;++i){
    mp.clear();
    for (int j=1;j<=m;++j)
      mp[a[i][j]].push_back(j);
    int l=0, r=mp.size();
    for (auto &it:mp){
      r--;
      for (auto o:it.se)
        ans[i][o]=max(b[i][o],l)+max(c[i][o],r)+1;
      l++;
    }
  }
  for (int i=1;i<=n;++i){
    for (int j=1;j<=m;++j)
      printf("%d ",ans[i][j]);
    puts("");
  }
}