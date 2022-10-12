#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long p,q,r,s;
    cin >> p >> q >> r >> s;
    long long v=min(q,s);
    q-=v;s-=v;
    for(long long i=0;i<min(10ll,q);i++){p*=10;}
    for(long long i=0;i<min(10ll,s);i++){r*=10;}
    if(p>r){cout << ">\n";}
    else if(p<r){cout << "<\n";}
    else{cout << "=\n";}
  }
  return 0;
}