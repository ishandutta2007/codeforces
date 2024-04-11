#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  set<char> cs;
  for(auto &nx : s){cs.insert(nx);}
  if(n<m){
    cout << s;
    for(int i=n;i<m;i++){
      cout << (*cs.begin());
    }cout << '\n';
    return 0;
  }
  auto it=cs.end();it--;
  char lg=(*it);
  int tg=m-1;
  while(s[tg]==lg){tg--;}
  for(int i=0;i<tg;i++){cout << s[i];}
  cout << (*cs.upper_bound(s[tg]));
  for(int i=tg+1;i<m;i++){cout << (*cs.begin());}
  cout << '\n';
  return 0;
}