#include<bits/stdc++.h>

using namespace std;

bool jud(long long x,vector<long long> &v){
  if(v.empty()){return false;}

  sort(v.begin(),v.end());
  if(x%2==1 && v.back()==2){return false;}

  long long sig=0;
  for(auto &nx : v){sig+=nx;}
  return (x<=sig);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m,k;
    cin >> n >> m >> k;
    vector<long long> a(k);
    for(auto &nx : a){cin >> nx;}

    vector<long long> v1;
    for(auto &nx : a){
      if((nx/n)<=1){continue;}
      v1.push_back(nx/n);
    }
    if(jud(m,v1)){cout << "Yes\n";continue;}

    vector<long long> v2;
    for(auto &nx : a){
      if((nx/m)<=1){continue;}
      v2.push_back(nx/m);
    }

    if(jud(n,v2)){cout << "Yes\n";continue;}
    cout << "No\n";
  }
  return 0;
}