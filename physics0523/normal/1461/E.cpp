#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long k,l,r,t,x,y;
  cin >> k >> l >> r >> t >> x >> y;
  long long wok=r-y;
  set<long long> passed;
  if(k+y<=r){
    k+=y;
    long long merg=r-k;
    if(x<y){
      merg/=(y-x);
      t-=merg;
      k+=merg*(y-x);
    }
  }

  while(t>0){
    if(passed.find(k)!=passed.end()){
      cout << "Yes\n";
      return 0;
    }
    passed.insert(k);

    long long nd=llceil(max(0ll,k-wok),x);

    if(nd==0){
      k-=x;
      long long merg=k-l;
      if(merg<0){cout << "No\n";return 0;}
      long long remday=8e18;
      if(x!=y){remday=1+merg/(x-y);}
      if(t<=remday){cout << "Yes\n";}
      else{cout << "No\n";}
      return 0;
    }

    nd=min(nd,t);
    t-=nd;
    k-=x*nd;
    // cerr << k << ' ' << t << '\n';
    if(!(l<=k && k<=r)){cout << "No\n";return 0;}
    if(t<=0){cout << "Yes\n";return 0;}
    k+=y;
  }
  cout << "Yes\n";
  return 0;
}