#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

long long circle_dist(long long x,long long y,long long p){
  if(x>y){swap(x,y);}
  return min(y-x,p+x-y);
}

long long solve(long long a,long long b,long long p,long long q){
  long long g=gcd(p,q);
  p/=g;q/=g;
  if(q%2){p*=2;q*=2;}
  p%=q;
  long long len=b-a+1;
  long long bsize=(sqrt(len)+0.5);
  while((bsize*bsize)>len){bsize--;}
  pl res={8e18,-1};
  while((bsize*bsize)<(b-a+1)){
    res=min(res,{circle_dist(((a*p)%q),(q/2),q),a});
    a++;
  }
  vector<pl> baby;
  for(long long i=0;i<bsize;i++){baby.push_back({(i*p)%q,i});}
  baby.push_back({8e18,8e18});
  sort(baby.begin(),baby.end());
  for(long long i=0;i<bsize;i++){
    long long tg=(q+(q/2)-((a+i*bsize)*p)%q)%q;
    long long pt=distance(baby.begin(),lower_bound(baby.begin(),baby.end(),make_pair(tg,-1ll)));
    pt%=bsize;
    res=min(res,{circle_dist(tg,baby[pt].first,q),a+i*bsize+baby[pt].second});

    pt+=(bsize-1);pt%=bsize;
    res=min(res,{circle_dist(tg,baby[pt].first,q),a+i*bsize+baby[pt].second});
  }
  return res.second;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,p,q;
    cin >> a >> b >> p >> q;
    cout << solve(a,b,p,q) << '\n';
  }
  return 0;
}