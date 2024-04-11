#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,r;
    int a,b;
    int p,q;
    int hand=0;
    cin >> l >> r >> a >> b >> p >> q;
    int dx=1,dy=1;
    while(a!=p && b!=q){
      if(a==l){dx=-1;}
      if(b==r){dy=-1;}
      if(l==1){dx=1;}
      if(r==1){dy=1;}
      a+=dx;b+=dy;
      hand++;
    }
    cout << hand << '\n';
  }
  return 0;
}