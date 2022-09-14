#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int p[200001];
int ans[200001];
void solve(){
  int n;cin>>n;
  for (int i=1;i<=n;i++) cin>>p[i];
  for (int i=1;i<=n;i++) ans[i]=0;
  for (int i=1;i<=n;i++){
      if (ans[i]) continue;
      vector<int>v={i};
      int cur=i;
      while (p[cur]!=i){
        cur=p[cur];
        v.push_back(cur);
      }
      for (auto i:v) ans[i]=(int)v.size();
  }
  for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
  cout<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;cin>>tt;
  while (tt--){
    solve();
  }
  return 0;
}