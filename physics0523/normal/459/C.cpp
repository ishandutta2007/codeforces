#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k,d;
  cin >> n >> k >> d;
  vector<vector<long long>> res(n);
  for(long long i=0;i<n;i++){
    long long ci=i;
    for(long long j=0;j<d;j++){
      res[i].push_back((ci%k)+1);
      ci/=k;
    }
    if(i==0){continue;}
    if(res[i]==res[0]){
      cout << "-1\n";
      return 0;
    }
  }
  for(int i=0;i<d;i++){
    for(int j=0;j<n;j++){
      if(j){cout << ' ';}
      cout << res[j][i];
    }cout << '\n';
  }
  return 0;
}