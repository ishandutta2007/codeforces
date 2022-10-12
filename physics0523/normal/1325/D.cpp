#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x,s;
  cin >> x >> s;
  if(x>s){cout << "-1\n";return 0;}
  vector<int> bk(62,0);
  for(int tg=0;tg<62;tg++){
    if(x&(1ll<<tg)){bk[tg]++;}
  }
  s-=x;
  if(s%2){cout << "-1\n";return 0;}
  s/=2;
  for(int tg=0;tg<62;tg++){
    if(s&(1ll<<tg)){bk[tg]+=2;}
  }
  vector<long long> res;
  while(1){
    long long add=0;
    for(int tg=0;tg<62;tg++){
      if(bk[tg]>0){
        bk[tg]--;
        add|=(1ll<<tg);
      }
    }
    if(add==0){break;}
    res.push_back(add);
  }
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}