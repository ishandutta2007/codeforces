#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x;
    cin >> x;
    int z=0,o=0;
    vector<int> m;
    for(int i=0;i<=30;i++){
      if(x&(1ll<<i)){
        if(o<2){m.push_back(i);}
        o++;
      }
      else{
        if(z<2){m.push_back(i);}
        z++;
      }
    }
    long long y=8e18;
    int sz=m.size();
    for(int i=0;i<(1<<sz);i++){
      long long cur=0;
      for(int j=0;j<sz;j++){
        if(i&(1<<j)){cur+=(1ll<<m[j]);}
      }
      if((x&cur)>0 && (x^cur)>0){y=min(y,cur);}
    }
    cout << y << '\n';
  }
  return 0;
}