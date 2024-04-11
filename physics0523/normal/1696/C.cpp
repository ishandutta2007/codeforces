#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

vector<pl> gen(vector<long long> a,long long k){
  vector<pl> res;
  for(auto &nx : a){
    long long cnt=1;
    while(nx%k==0){
      nx/=k;
      cnt*=k;
    }
    res.push_back({nx,cnt});
  }
  return res;
}

vector<pl> comp(vector<pl> a){
  vector<pl> res;
  int sz=a.size();
  a.push_back({-1,-1});
  pl cur=a[0];

  for(int i=1;i<=sz;i++){
    if(cur.first==a[i].first){
      cur.second+=a[i].second;
    }
    else{
      res.push_back(cur);
      cur=a[i];
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    long long m;
    cin >> m;
    vector<long long> b(m);
    for(auto &nx : b){cin >> nx;}

    vector<pl> pa=gen(a,k);
    pa=comp(pa);
    vector<pl> pb=gen(b,k);
    pb=comp(pb);
    if(pa==pb){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}