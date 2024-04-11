#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v]++;
    }
    int lg=0;
    for(auto &nx : mp){lg=max(lg,nx.second);}
    int res=0;
    while(lg<n){
      res++;
      int dlt=min(lg,n-lg);
      res+=dlt;
      lg+=dlt;
    }
    cout << res << '\n';
  }
  return 0;
}