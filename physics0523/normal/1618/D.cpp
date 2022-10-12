#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    long long res=0;
    map<long long,int> mp;
    for(int i=0;i<min(n,2*k);i++){
      mp[a[i]]++;
    }
    int mh=0;
    for(auto &nx : mp){mh=max(mh,nx.second);}
    res+=max(0,mh-k);
    for(int i=2*k;i<n;i++){res+=a[i];}
    cout << res << '\n';
  }
  return 0;
}