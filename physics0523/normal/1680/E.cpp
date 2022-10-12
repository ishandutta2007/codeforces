#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s0,s1;
    cin >> n >> s0 >> s1;
    int l=1e9,r=-1e9;
    for(int i=0;i<n;i++){
      if(s0[i]=='*' || s1[i]=='*'){l=min(l,i);r=max(r,i);}
    }
    int d0=0,d1=0;
    for(int i=l;i<=r;i++){
      int nd0=1e9,nd1=1e9;

      if(s0[i]=='.' && s1[i]=='.'){
        nd0=min(d0+1,d1+2);
        nd1=min(d0+2,d1+1);
      }

      if(s0[i]=='.' && s1[i]=='*'){
        nd0=min(d0+2,d1+2);
        nd1=min(d0+2,d1+1);
      }

      if(s0[i]=='*' && s1[i]=='.'){
        nd0=min(d0+1,d1+2);
        nd1=min(d0+2,d1+2);
      }

      if(s0[i]=='*' && s1[i]=='*'){
        nd0=min(d0+2,d1+2);
        nd1=min(d0+2,d1+2);
      }

      d0=nd0;d1=nd1;
    }
    cout << min(d0,d1)-1 << '\n';
  }
  return 0;
}