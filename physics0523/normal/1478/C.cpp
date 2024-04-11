#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    map<long long,long long> mp;
    for(long long i=0;i<2*n;i++){
      long long v;
      cin >> v;
      mp[v]++;
    }
    bool iserr=false;
    vector<long long> a;
    for(auto &nx : mp){
      if(nx.second!=2){iserr=true;break;}
      a.push_back(nx.first);
    }
    if(iserr){cout << "NO\n";continue;}
    for(auto &nx : a){
      if(nx%2){iserr=true;}
    }
    if(iserr){cout << "NO\n";continue;}
    if(a.size()!=n){iserr=true;continue;}
    if(iserr){cout << "NO\n";continue;}

    long long basd=0;
    reverse(a.begin(),a.end());
    long long dvd=2*n-2,ce=2;
    for(long long i=1;i<n;i++){
      if((a[i-1]-a[i])%dvd){iserr=true;}
      basd+=ce*((a[i-1]-a[i])/dvd);
      dvd-=2;ce+=2;
    }
    if(iserr){cout << "NO\n";continue;}
    //cout << basd << '\n';
    if(basd>=a[n-1]){iserr=true;}
    if(iserr){cout << "NO\n";continue;}
    if((a[n-1]-basd)%(2*n)){iserr=true;}
    if(iserr){cout << "NO\n";continue;}
    cout << "YES\n";
  }
  return 0;
}
// 12 8
// * 2 * * *