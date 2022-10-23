#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

bool solve(long long n,long long k,vector<long long> a){
  if(k==0){return true;}

  a.push_back(-7e18);

  long long low=0,cur=0,high=0;
  queue<pl> q;
  for(int i=k+1;i<=n;i++){
    cur+=a[i];
    if(low>cur){
      low=cur;
      q.push({-low,high});
      // cout << -low << "," << high << "\n";
    }
    high=max(high,cur);
  }

  cur=a[k];
  while(cur>=q.front().first){q.pop();}
  for(int i=k-1;i>=0;i--){
    cur+=a[i];
    while(cur>=q.front().first){q.pop();}
    long long h=cur+q.front().second;
    if(h<0){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    k--;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}

    bool ok=solve(n,k,a);
    k=(n-1)-k;
    reverse(a.begin(),a.end());
    ok|=solve(n,k,a);

    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}