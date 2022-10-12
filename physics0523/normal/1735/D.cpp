#include<bits/stdc++.h>

using namespace std;

int k;
long long last(long long a,long long b){
  long long c=0;
  for(int i=0;i<k;i++){
    long long mask=(1ll<<(2*i))+(1ll<<(2*i+1));
    if((a&mask)==(b&mask)){
      c|=(a&mask);
    }
    else{
      c|=((a&mask)^(b&mask));
    }
  }
  return c;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;
  vector<long long> c(n,0);
  map<long long,int> mp;
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      long long v;
      cin >> v;
      v++;
      c[i]|=(v<<(2*j));
    }
    mp[c[i]]=i;
  }

  vector<long long> cnt(n,0);
  vector<vector<int>> v;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      long long las=last(c[i],c[j]);
      if(mp.find(las)!=mp.end()){
        cnt[i]++;
        cnt[j]++;
        if(j<mp[las]){
          v.push_back({i,j,mp[las]});
        }
      }
    }
  }
  long long res=0;
  for(auto &nx : v){
    res+=cnt[nx[0]];
    res+=cnt[nx[1]];
    res+=cnt[nx[2]];
    res-=6;
  }
  res/=4;
  cout << res << "\n";
  return 0;
}