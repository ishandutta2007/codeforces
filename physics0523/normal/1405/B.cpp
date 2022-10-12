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
    cin >> n;
    long long sig=0,dis=0;
    long long merg=0;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      if(v>0){sig+=v;merg+=v;}
      if(v<0){
        long long use=min(merg,-v);
        merg-=use;
        dis+=use;
      }
    }
    cout << sig-dis << '\n';
  }
  return 0;
}