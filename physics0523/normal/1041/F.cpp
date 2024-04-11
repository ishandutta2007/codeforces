#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

bool hit(long long x,long long k,long long a,long long d){
  long long val=abs(x-a);
  if(val%d){return false;}
  val/=d;
  return ((val%2)==k);
}

long long get_rand(long long lim,mt19937_64 &eg){
  return (long long)(eg()%lim);
}

vector<long long> pfact_unique(long long x){
  vector<long long> p;
  for(long long i=2;i*i<=x;i++){
    if(x%i==0){
      p.push_back(i);
      while(x%i==0){x/=i;}
    }
  }
  if(x>1){p.push_back(x);}
  return p;
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n,y;
  vector<pl> pts;
  long long res=0;
  map<long long,long long> mp;
  for(int i=0;i<2;i++){
    cin >> n >> y;
    for(int j=0;j<n;j++){
      long long x;
      cin >> x;
      mp[x]++;
      pts.push_back({x,i});
      if(hit(x,i,0,1)){res++;}
    }
  }

  for(auto &nx : mp){
    res=max(res,nx.second);
  }
  n=pts.size();
  res=max(res,n-res);

  for(long long d=0;d<=30;d++){
    long long m=2*(1ll<<d);
    map<long long,long long> mp;
    for(auto &nx : pts){
      long long tg=nx.first;
      if(nx.second){tg+=(1ll<<d);}
      tg%=m;
      mp[tg]++;
    }
    for(auto &nx : mp){
      res=max(res,nx.second);
    }
  }

  // tbh below is needless
  // for(int tr=0;tr<50;tr++){
  //   long long p=0,q=0;
  //   while(p==q){
  //     p=get_rand(n,engine);
  //     q=get_rand(n,engine);
  //   }
  //   long long dif=abs(pts[p].first-pts[q].first);
  //   if(pts[p].second==pts[q].second){
  //     if(dif%2){continue;}
  //     dif/=2;
  //   }
  //   vector<long long> pf=pfact_unique(dif);
  //   for(auto &nx : pf){
  //     long long ca=pts[p].first;
  //     ca+=(nx*pts[p].second);
  //     long long cd=nx;
  //     long long cur=0;
  //     for(auto &ny : pts){
  //       if(hit(ny.first,ny.second,ca,cd)){cur++;}
  //     }
  //     res=max(res,cur);
  //   }
  // }
  cout << res << '\n';
  return 0;
}