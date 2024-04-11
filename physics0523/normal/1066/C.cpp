#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  int cl=0,cr=1;
  vector<int> pt(262144,-1e9);
  while(q>0){
    q--;
    string s;
    cin >> s;
    int id;
    cin >> id;
    if(s=="L"){
      pt[id]=cl;
      cl--;
    }
    if(s=="R"){
      pt[id]=cr;
      cr++;
    }
    if(s=="?"){
      cout << min(pt[id]-cl,cr-pt[id])-1 << '\n';
    }
  }
  return 0;
}