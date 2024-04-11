#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,q;
  cin >> n >> q;
  long long wh=0,wc=0,sig=0;
  map<int,long long> mp;
  for(int i=0;i<n;i++){
    cin >> mp[i];
    sig+=mp[i];
  }

  while(q>0){
    q--;
    int typ;
    cin >> typ;
    if(typ==1){
      int tg;
      long long x;
      cin >> tg >> x;
      tg--;
      if(mp.find(tg)==mp.end()){wc--;}
      sig-=mp[tg];
      sig+=x;
      mp[tg]=x;
    }
    else{
      mp.clear();
      sig=0;
      cin >> wh;
      wc=n;
    }
    cout << sig+wh*wc << '\n';
   }
  return 0;
}