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
    map<long long,long long> mp;
    for(int i=0;i<m;i++){
      long long v;
      cin >> v;
      mp[v]++;
    }

    long long st=1,fi=1e6;
    while(st<=fi){
      long long te=(st+fi)/2;
      long long sz=0,merg=n*(te/2);
      for(auto &nx : mp){
        long long del=min(te,nx.second);
        sz+=del;
        merg-=(te/2);
        merg+=(te-del)/2;
      }
      long long rem=m-sz;
      if(merg < rem){st=te+1;}else{fi=te-1;}
    }
    cout << st << "\n";
  }
  return 0;
}