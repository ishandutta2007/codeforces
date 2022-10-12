#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  vector<long long> b(n),g(m);
  for(auto &nx : b){cin >> nx;}
  for(auto &nx : g){cin >> nx;}
  sort(b.begin(),b.end());
  sort(g.begin(),g.end());
  if(b[n-1]>g[0]){cout << "-1\n";return 0;}
  long long res=0;
  for(int i=0;i<n;i++){res+=b[i]*m;}
  for(int i=1;i<m;i++){res+=(g[i]-b[n-1]);}
  if(b[n-1]!=g[0]){res+=(g[0]-b[n-2]);}
  cout << res << '\n';
  return 0;
}