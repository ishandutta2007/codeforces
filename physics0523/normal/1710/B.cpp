#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;

    vector<long long> x(n),p(n);
    vector<pl> eve;
    for(int i=0;i<n;i++){
      cin >> x[i] >> p[i];
      eve.push_back({x[i]-p[i],1});
      eve.push_back({x[i],-2});
      eve.push_back({x[i]+p[i],1});
    }

    long long dr=0,r=0;
    eve.push_back({-8e18,0});
    eve.push_back({8e18,0});
    sort(eve.begin(),eve.end());
    int ec=eve.size()-1;
    vector<pl> fld;
    for(int i=0;i<ec;i++){
      dr+=eve[i].second;
      r+=dr*(eve[i+1].first-eve[i].first);

      // cout << eve[i+1].first << " " << r << "\n";
      if(r>m){
        fld.push_back({eve[i+1].first,m-r});
      }
    }

    if(fld.empty()){
      for(int i=0;i<n;i++){
        cout << "1";
      }cout << "\n";
      continue;
    }

    string res;
    vector<pl> jv;
    for(auto &nx : fld){
      jv.push_back(nx);
    }
    for(int i=0;i<n;i++){
      res.push_back('1');
      jv.push_back({x[i],i});
    }
    long long eval;
    jv.push_back({-8e18,0});
    jv.push_back({8e18,0});
    int jc=jv.size();

    eval=-8e18;
    sort(jv.begin(),jv.end());
    for(int i=1;i<jc-1;i++){
      if(jv[i].second<0){
        eval=max(eval,-jv[i].second);
      }
      else{
        if(p[jv[i].second]<eval){res[jv[i].second]='0';}
      }
      if(eval>=0){
        eval+=llabs(jv[i+1].first-jv[i].first);
      }
    }

    eval=-8e18;
    reverse(jv.begin(),jv.end());
    for(int i=1;i<jc-1;i++){
      if(jv[i].second<0){
        eval=max(eval,-jv[i].second);
      }
      else{
        if(p[jv[i].second]<eval){res[jv[i].second]='0';}
      }
      if(eval>=0){
        eval+=llabs(jv[i+1].first-jv[i].first);
      }
    }

    cout << res << "\n";
  }
  return 0;
}