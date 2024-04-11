#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;cin >> k;
  string s;cin >> s;
  reverse(s.begin(),s.end());
  s='*'+s;
  vector<int> arr(1<<(k+1),1);
  for(int i=(1<<k)-1;i>=1;i--){
    arr[i]=0;
    if(s[i]!='0'){arr[i]+=arr[i*2];}
    if(s[i]!='1'){arr[i]+=arr[i*2+1];}
    //cout << s[i] << ':' << arr[i] << ' ' << arr[i*2] << ' ' << arr[i*2+1] << '\n';
  }
  int q;cin >> q;
  while(q>0){
    q--;
    int tg;
    string upd;
    cin >> tg >> upd;
    tg=(1<<k)-tg;
    s[tg]=upd[0];
    while(tg>=1){
      arr[tg]=0;
      if(s[tg]!='0'){arr[tg]+=arr[tg*2];}
      if(s[tg]!='1'){arr[tg]+=arr[tg*2+1];}
      //cout << tg << ' ' << s[tg] << ' ' << arr[tg] << ' ';
      tg/=2;
    }
    cout << arr[1] << '\n';
  }
  return 0;
}