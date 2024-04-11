#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    set<int> res;

    int p,q;
    p=(a+b)/2;
    q=(a+b)-p;
    for(int i=0;i<=a;i++){
      int ah,ab,bh,bb;
      ah=i;ab=a-i;
      bh=q-ab;bb=p-ah;
      if(0<=ah && 0<=ab && 0<=bh && 0<=bb){res.insert(ab+bb);}
    }

    q=(a+b)/2;
    p=(a+b)-q;
    for(int i=0;i<=a;i++){
      int ah,ab,bh,bb;
      ah=i;ab=a-i;
      bh=q-ab;bb=p-ah;
      if(0<=ah && 0<=ab && 0<=bh && 0<=bb){res.insert(ab+bb);}
    }

    cout << res.size() << '\n';
    bool fl=false;
    for(auto &nx : res){
      if(fl){cout << ' ';}
      cout << nx;
      fl=true;
    }cout << '\n';
  }
  return 0;
}