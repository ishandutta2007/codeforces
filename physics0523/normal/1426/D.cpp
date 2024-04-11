#include<bits/stdc++.h>

using namespace std;

int main(){
  map<long long,int> mp;
  long long n,v,sig=0,res=0,pv=0;
  cin >> n;
  mp[0]=499;
  for(int i=500;i<500+n;i++){
    cin >> v;
    sig+=v;
    //cout << mp[sig] <<'\n';
    if(mp[sig]!=0 && pv<=mp[sig]){
      res++;
      pv=i-1;
    }
    mp[sig]=i;
  }
  cout << res << '\n';
}