#include<bits/stdc++.h>

using namespace std;
using pic=pair<int,char>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int l;
  string s;
  cin >> l >> s;
  int q;
  cin >> q;
  map<pic,int> mp;
  while(q>0){
    q--;
    int m;
    string c;
    cin >> m >> c;
    if(mp[{m,c[0]}]!=0){
      cout << mp[{m,c[0]}] << '\n';
      continue;
    }
    int res=0,fi=0,cnt=0;
    for(int st=0;st<l;st++){
      while(cnt<=m){
        //cerr << st << ' ' << fi << ' ' << cnt << '\n';
        res=max(res,fi-st);
        if(fi==l){break;}
        if(s[fi]!=c[0]){cnt++;}
        fi++;
      }
      if(s[st]!=c[0]){cnt--;}
    }
    mp[{m,c[0]}]=res;
    cout << res << '\n';
  }
  return 0;
}