#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

vector<long long> bk(string &s){
  vector<long long> res(26,0);
  for(auto &nx : s){
    res[nx-'a']++;
  }
  return res;
}

#define MXM 110000

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a,b,c;
  cin >> a >> b >> c;
  vector<long long> ab=bk(a);
  vector<long long> bb=bk(b);
  vector<long long> cb=bk(c);
  long long br=0,cr=0;
  long long j=MXM;
  for(long long i=0;(i<=MXM && j>=0);i++){
    while(1){
      bool isok=true;
      for(long long ch=0;ch<26;ch++){
        if(ab[ch]<bb[ch]*i+cb[ch]*j){isok=false;break;}
      }
      if(isok){break;}
      j--;
      if(j<0){break;}
    }
    if(j>=0 && (br+cr)<=(i+j)){br=i;cr=j;}
  }
  for(long long out=0;out<br;out++){cout << b;}
  for(long long out=0;out<cr;out++){cout << c;}
  for(long long ch=0;ch<26;ch++){
    long long rem=ab[ch]-bb[ch]*br-cb[ch]*cr;
    for(long long out=0;out<rem;out++){
      cout << ((char)('a'+ch));
    }
  }
  cout << '\n';
  return 0;
}