#include<bits/stdc++.h>

using namespace std;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

vector<__int128> a;
void genluck(){
  for(int dg=1;dg<=18;dg++){
    for(int i=0;i<(1<<dg);i++){
      __int128 v=0;
      for(int j=0;j<dg;j++){
        v*=10;
        if(i&(1<<j)){v+=7;}
        else{v+=4;}
      }
      a.push_back(v);
    }
  }
  sort(a.begin(),a.end());
}

__int128 getval(){
  long long v;
  cin >> v;
  return ((__int128)v);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  genluck();
  __int128 n,k;
  n=getval();
  k=getval();
  __int128 minseg=8e18,res=0;
  vector<__int128> llis;
  vector<__int128> rlis;
  for(int i=0;i<n;i++){
    __int128 l,r;
    l=getval();
    r=getval();
    llis.push_back(l);
    rlis.push_back(r);
    minseg=min(minseg,r-l+1);
  }
  sort(llis.begin(),llis.end());
  reverse(llis.begin(),llis.end());
  sort(rlis.begin(),rlis.end());
  reverse(rlis.begin(),rlis.end());
  __int128 cost=0;
  for(auto &nx : llis){cost+=max((__int128)0,nx-4);}
  for(auto &nx : rlis){cost+=max((__int128)0,4-nx);}
  while(llis.size()>0 && llis.back()<4){llis.pop_back();}
  while(rlis.size()>0 && rlis.back()<4){rlis.pop_back();}
  __int128 l=0,r=0;
  __int128 sz=a.size();
  while(1){
    // if(a[r]<777){
    //   cout << a[l] << ' ' << a[r] << ' ' << cost << '\n';
    //   for(auto &nx : llis){cout << nx << ' ';}cout << '\n';
    //   for(auto &nx : rlis){cout << nx << ' ';}cout << '\n';
    // }
    if(l<r && ((a[r]-a[l]+1)>minseg || cost>k)){
      cost+=a[l]*llis.size();
      l++;
      if(l==a.size()){break;}
      while(llis.size()>0 && llis.back()<a[l]){
        cost-=llis.back();
        llis.pop_back();
      }
      cost-=a[l]*llis.size();
    }
    else{
      if((a[r]-a[l]+1)<=minseg && cost<=k){
        res=max(res,r-l+1);
      }
      cost-=a[r]*(n-rlis.size());
      r++;
      if(r==a.size()){break;}
      while(rlis.size()>0 && rlis.back()<a[r]){
        cost-=rlis.back();
        rlis.pop_back();
      }
      cost+=a[r]*(n-rlis.size());
    }
  }
  cout << res << '\n';
  return 0;
}