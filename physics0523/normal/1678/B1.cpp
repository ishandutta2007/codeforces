#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    int p=0,q=0,r1=0;
    for(int i=0;i<l;i+=2){
      int np=1e9,nq=1e9;
      int sig=(s[i]-'0')+(s[i+1]-'0');
      if(sig==0){
        np=min(p,q+1);
      }
      else if(sig==1){
        np=min(p,q+1);
        nq=min(p+1,q);
        r1++;
      }
      else{
        nq=min(p+1,q);
      }
      p=np;q=nq;
    }
    cout << r1 << '\n';
  }
  return 0;
}