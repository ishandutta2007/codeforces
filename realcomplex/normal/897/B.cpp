#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k,p;

ll ans = 0;

ll conv(string a){
  string v = a;
  reverse(v.begin(),v.end());
  a += v;
  ll ri = 1;
  ll an = 0;
  for(int j = a.size()-1;j>=0;j--){
    an += (a[j]-48)*ri;
    ri*=10;
  }
  return an;
}

void gen(int l,int i,string cur){
  if(i==l){
    k--;
    ans += conv(cur);
    ans %= p;
    if(k==0){
      cout << ans << "\n";
      exit(0);
    }
  }
  else{
    for(char li = '0';li<='9';li++){
      if(i==0&&li=='0')continue;
      gen(l,i+1,cur+li);
    }
  }
}


int main(){
  cin >> k >> p;
  for(int j = 1;j<10;j++)
    gen(j,0,"");
  return 0;
}