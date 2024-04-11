#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;

    vector<vector<long long>> a(n,vector<long long>(m,0));
    map<long long,long long> mp;
    vector<long long> grv(n,0);
    for(long long i=0;i<n;i++){
      for(long long j=0;j<m;j++){
        cin >> a[i][j];
        grv[i]+=j*(a[i][j]);
      }
      mp[grv[i]]++;
    }

    long long tg;
    long long bas;
    for(auto &nx : mp){
      if(nx.second==1){tg=nx.first;}
      else{bas=nx.first;}
    }
    for(long long i=0;i<n;i++){
      if(grv[i]==tg){
        cout << i+1 << " " << grv[i]-bas << "\n";
        break;
      }
    }
  }
  return 0;
}