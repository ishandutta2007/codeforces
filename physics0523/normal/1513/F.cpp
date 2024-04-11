#include<bits/stdc++.h>

using namespace std;
using pi=pair<long long,long long>;

long long zt(long long a,long long b){return max(a,b)-min(a,b);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n),b(n);
  for(auto &nx : a){cin >> nx;}
  for(auto &nx : b){cin >> nx;}
  long long zk=0;
  vector<pair<pi,long long>> vp;
  for(long long i=0;i<n;i++){
    zk+=zt(a[i],b[i]);
    if(a[i]<b[i]){
      vp.push_back(make_pair(make_pair(a[i],-b[i]),1ll));
    }
    else{
      vp.push_back(make_pair(make_pair(b[i],-a[i]),-1ll));
    }
  }
  long long res=zk;
  sort(vp.begin(),vp.end());
  long long fp=-1000000007,fm=-1000000007;
  for(auto &nx : vp){
    //cout << nx.first.first << ' ' << nx.first.second << ',' << nx.second << '\n';
    //cout << fp << ' ' << fm << '\n';
    if(nx.second==1){
      res=min(zk-2ll*(min(fm,-nx.first.second)-nx.first.first),res);
      fp=max(-nx.first.second,fp);
    }
    if(nx.second==-1){
      res=min(zk-2ll*(min(fp,-nx.first.second)-nx.first.first),res);
      fm=max(-nx.first.second,fm);
    }
  }
  cout << res << '\n';
  return 0;
}