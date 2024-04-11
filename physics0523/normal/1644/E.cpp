#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    string s;
    cin >> n >> s;

    int fl=0;
    for(auto &nx : s){
      if(nx=='R'){fl|=1;}
      else{fl|=2;}
    }
    if(fl!=3){cout << n << '\n';continue;}

    long long rw=n,dw=n;
    for(auto &nx : s){
      if(nx=='R'){rw--;}
      else{dw--;}
    }
    //cout << rw << ' ' << dw << '\n';

    long long res=0;
    int rp,dp;
    int l=s.size();
    for(int i=0;i<l;i++){
      if(s[i]=='R'){rp=i;break;}
    }
    dp=-1;
    long long pt=1,hrem=n;
    for(int i=0;i<l;i++){
      if(s[i]=='R'){
        long long ce=1;
        if(i==rp){ce=rw;}
        pt+=ce;
      }
      else{
        long long ce=1;
        if(i==dp){ce=dw;}
        res+=ce*pt;
        hrem-=ce;
      }
    }
    res+=pt*hrem;

    rp=-1;
    for(int i=0;i<l;i++){
      if(s[i]=='D'){dp=i;break;}
    }
    pt=0;
    for(int i=0;i<l;i++){
      if(s[i]=='R'){
        long long ce=1;
        if(i==rp){ce=rw;}
        pt+=ce;
      }
      else{
        long long ce=1;
        if(i==dp){ce=dw;}
        res-=ce*pt;
      }
    }
    cout << res << '\n';
  }
  return 0;
}