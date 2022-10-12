#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> v(n);
  long long sig=0;
  for(auto &nx : v){
    cin >> nx;
    sig+=nx;
  }
  long long bn=0,subt=0;
  vector<long long> tim(n+1,0);
  vector<pl> pv;
  for(int i=0;i<n;i++){
    subt+=v[i];
    bn=max(bn,llceil(subt,(i+1)));
    tim[i+1]=max(bn,llceil(sig,(i+1)));

    pv.push_back({tim[i+1],-(i+1)});
  }
  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    long long t;
    cin >> t;
    pv.push_back({t,i});
  }
  sort(pv.begin(),pv.end());
  long long cres=8e18;
  vector<long long> res(q);
  for(auto &nx : pv){
    if(nx.second<0){
      cres=min(cres,-nx.second);
    }
    else{
      res[nx.second]=cres;
    }
  }
  for(auto &nx : res){
    if(nx>1e9){nx=-1;}
    cout << nx << '\n';
  }
  return 0;
}