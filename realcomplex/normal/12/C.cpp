#include <bits/stdc++.h>

using namespace std;

int cnt[105];
map<string,int>v;
int p = 0;

void add(string a){
  if(v[a]==0)v[a]=(++p);
}

int main(){
  int n,m; 
  cin >> n >> m;
  int cost[n]; 
  for(int i = 0;i<n;i++){
    cin >> cost[i];
  }
  sort(cost,cost+n);
  string a;
  for(int j = 0;j<m;j++){
    cin >> a;
    add(a);
    cnt[v[a]]++;
  }
  sort(cnt+1,cnt+p+1);
  int ans = 0;
  int l = 0;
  for(int i = p;i>=1;i--){
    ans+=cnt[i]*cost[l];
    l++;
  }
  cout << ans << " ";
  ans = 0;
  l=n-1;
  for(int i = p;i>=1;i--){
    ans+=cnt[i]*cost[l];
    l--;
  }
  cout << ans;
  cout << "\n";
  return 0;
}